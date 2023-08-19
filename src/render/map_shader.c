#include "map_shader.h"
#include "math/lerp.h"
#include <ft_printf.h>

t_fdf_color fdf_map_shader(t_vec2 pos, int n, int len, void *raw_data)
{
	t_fdf_map_shader_data *data;
	int i;
	float z;
	float t;

	data = raw_data;
	if (pos.x < 0 || pos.x >= data->w || pos.y < 0 || pos.y >= data->h)
		return (t_fdf_color){0};
	i = pos.y * data->w + pos.x;
	t = (float)n / len;
	z = fdf_lerp(t, data->a->z, data->b->z);
	if (z < data->zbuffer[i])
	{
		data->zbuffer[i] = z;
		return (fdf_lerp_rgb(t, data->a->color, data->b->color));
	}
	return (t_fdf_color){0};
}
