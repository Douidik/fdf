#include "color.h"

t_fdf_color fdf_color_hex(uint32_t v)
{
	return (t_fdf_color){.v = v};
}
