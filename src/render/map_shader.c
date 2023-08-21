/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_shader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuppan <jsuppan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 20:59:07 by jsuppan           #+#    #+#             */
/*   Updated: 2023/08/19 20:59:59 by jsuppan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_shader.h"
#include "math/lerp.h"
#include <ft_printf.h>

t_fdf_color	fdf_map_shader(t_vec2 pos, int n, int len, void *raw_data)
{
	t_fdf_map_shader_data	*data;
	int						i;
	float					z;
	float					t;

	data = raw_data;
	i = pos.y * data->w + pos.x;
	if (len != 0)
		t = (float)n / len;
	else
		t = 1;
	z = fdf_lerp(t, data->a->z, data->b->z);
	if (z < data->zbuffer[i])
	{
		data->zbuffer[i] = z;
		return (fdf_lerp_rgb(t, data->a->color, data->b->color));
	}
	return ((t_fdf_color){0});
}
