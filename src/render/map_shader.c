#include "map_shader.h"
#include "math/lerp.h"

t_fdf_color fdf_map_shader(t_vec2 pos, int n, int len, void *raw_data)
{
	t_fdf_map_shader_data *data;
	int i;
	float z;

	data = raw_data;
	i = pos.y * data->w + pos.x;
	z = fdf_lerp(n, len, data->a->z, data->b->z);
	if (z < data->zbuffer[i])
	{
		data->zbuffer[i] = z;
		return (fdf_lerp_rgb(n, len, data->a->color, data->b->color));
	}
	return (t_fdf_color){0};
}
