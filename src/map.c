/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuppan <jsuppan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 20:07:51 by jsuppan           #+#    #+#             */
/*   Updated: 2023/08/19 20:08:07 by jsuppan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "fdf.h"
#include "util/cmp.h"
#include <ft_printf.h>
#include <libft.h>
#include <math.h>
#include <stdlib.h>

t_fdf_map	*fdf_map_init(t_fdf_map *map, int w, int h)
{
	map->scroll = 6;
	map->w = w;
	map->h = h;
	map->verts = ft_calloc(map->w * map->h, sizeof(int));
	map->colors = ft_calloc(map->w * map->h, sizeof(int));
	if (!map->verts || !map->colors)
		return (fdf_map_free(map));
	return (map);
}

t_fdf_map	*fdf_map_free(t_fdf_map *map)
{
	if (map != NULL)
	{
		if (map->verts != NULL)
			free(map->verts);
		if (map->colors != NULL)
			free(map->colors);
	}
	return (NULL);
}

float	fdf_map_factor(t_fdf_map *map)
{
	return ((float)map->scroll / fabsf((float)map->max - map->min) / 3);
}

#define FDF_SCROLL_UP (5)
#define FDF_SCROLL_DOWN (4)

int	fdf_map_on_mouse(int m, int x, int y, t_fdf *fdf)
{
	t_fdf_map	*map;

	(void)x;
	(void)y;
	map = fdf->map;
	if (m == FDF_SCROLL_UP || m == FDF_SCROLL_DOWN)
	{
		if (m == FDF_SCROLL_UP)
			map->scroll--;
		else
			map->scroll++;
		fdf->cam.obsolete = 1;
		return (1);
	}
	return (0);
}
