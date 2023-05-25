#ifndef FDF_MEM_H
#define FDF_MEM_H

#include <stddef.h>

void *fdf_memset(void *dst, int value, size_t size);
void *fdf_memcpy(void *dst, void *src, size_t size);

#endif