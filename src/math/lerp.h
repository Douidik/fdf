#ifndef FDF_LERP_H
#define FDF_LERP_H

#include "render/color.h"
#include <stddef.h>

int fdf_lerp(int t, int u, int a, int b);
t_fdf_color fdf_lerp_rgb(int t, int u, t_fdf_color a, t_fdf_color b);
t_fdf_color fdf_lerp_rgb_gradient(int t, int u, t_fdf_color s[], size_t len);

#endif
