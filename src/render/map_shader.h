#ifndef FDF_MAP_SHADER_H
#define FDF_MAP_SHADER_H

#include "renderer.h"

struct s_fdf_render_layer;

typedef struct s_fdf_map_shader_data
{
	t_fdf_vertex *a;
	t_fdf_vertex *b;
	float *zbuffer;
	int w;
	int h;
} t_fdf_map_shader_data;

t_fdf_color fdf_map_shader(t_vec2 pos, int n, int len, void *raw_data);

#endif
