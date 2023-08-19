#include "read_fd.h"
#include "mem.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define FDF_RDBUF_INIT 32
#define FDF_RDBUF_FACTOR 2

char *fdf_read_push(char *str, ssize_t len, ssize_t cap)
{
	char *new;

	new = malloc(cap + 1);
	if (new != NULL)
		fdf_memcpy(new, str, len);
	free(str);
	return (new);
}

char *fdf_read_fd(int fd)
{
	ssize_t rdsize;
	size_t len;
	size_t cap;
	char *str;

	len = 0;
	cap = FDF_RDBUF_INIT;
	str = malloc(cap + 1);
	while (str != NULL && fd != -1)
	{
		rdsize = read(fd, str + len, cap - len);
		if (rdsize < 0)
			return (free(str), NULL);
		if (rdsize != (ssize_t)(cap - len))
		{
			str[len + rdsize] = '\0';
			return (str);
		}
		len = len + rdsize;
		cap = cap * FDF_RDBUF_FACTOR;
		str = fdf_read_push(str, len, cap);
	}
	return (NULL);
}
