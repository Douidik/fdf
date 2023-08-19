/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuppan <jsuppan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 20:08:17 by jsuppan           #+#    #+#             */
/*   Updated: 2023/08/19 20:08:50 by jsuppan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "render/color.h"
# include <stddef.h>
# include <stdint.h>

struct	s_fdf;

typedef struct s_fdf_map
{
	int			*verts;
	t_fdf_color	*colors;
	int			scroll;
	int			w;
	int			h;
	int			min;
	int			max;
}	t_fdf_map;

t_fdf_map	*fdf_map_init(t_fdf_map *map, int w, int h);
t_fdf_map	*fdf_map_free(t_fdf_map *map);
int			fdf_map_on_mouse(int m, int x, int y, struct s_fdf *fdf);
float		fdf_map_factor(t_fdf_map *map);

#endif
