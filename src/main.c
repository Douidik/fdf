#include "fdf.h"
#include "map.h"
#include "parse/parser.h"
#include <fcntl.h>
#include <ft_printf.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	t_fdf *fdf;
	t_fdf_parser *parser;
	t_fdf_map map;
	int fd;

	if (argc < 2)
		return (ft_printf("no map specified in program arguments\n"), 1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (ft_printf("cannot open file from '%s'\n", argv[1]), 1);
	parser = fdf_parser_new(fd);
	close(fd);
	if (!parser)
		return (ft_printf("cannot read file from '%s'\n", argv[1]), 1);
	if (!fdf_parse_map(parser, &map))
		return (fdf_parser_free(parser), ft_printf("cannot parse file from '%s'\n", argv[1]), 1);
	fdf = fdf_new(&map, argv[1]);
	fdf_parser_free(parser);
	if (!fdf)
		return (fdf_map_free(&map), 1);
	fdf_run(fdf);
	fdf_free(fdf);
	fdf_map_free(&map);
	return (0);
}
