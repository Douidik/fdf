#ifndef FDF_COLOR_H
#define FDF_COLOR_H

#include <stdint.h>

typedef union u_fdf_color
{
	struct
	{
		uint8_t r;
		uint8_t g;
		uint8_t b;
		uint8_t a;
	};
	uint32_t v;
} t_fdf_color;

#endif
