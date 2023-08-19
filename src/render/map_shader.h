/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_shader.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuppan <jsuppan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 20:58:41 by jsuppan           #+#    #+#             */
/*   Updated: 2023/08/19 20:59:58 by jsuppan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_SHADER_H
# define MAP_SHADER_H

# include "renderer.h"

struct	s_fdf_render_layer;

typedef struct s_fdf_map_shader_data
{
	t_fdf_vertex	*a;
	t_fdf_vertex	*b;
	float			*zbuffer;
	int				w;
	int				h;
}	t_fdf_map_shader_data;

t_fdf_color	fdf_map_shader(t_vec2 pos, int n, int len, void *raw_data);

#endif
