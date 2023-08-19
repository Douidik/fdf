#ifndef FDF_LERP_H
#define FDF_LERP_H

#include "render/color.h"
#include <stddef.h>

int fdf_lerp(float t, int a, int b);
t_fdf_color fdf_lerp_rgb(float t, t_fdf_color a, t_fdf_color b);
t_fdf_color fdf_lerp_rgbs(float t, t_fdf_color p[], size_t len);

#endif
