/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cohen_sutherland.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuppan <jsuppan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 21:27:02 by jsuppan           #+#    #+#             */
/*   Updated: 2023/08/19 21:27:39 by jsuppan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cohen_sutherland.h"
#include "intersect.h"

enum e_cohen_sutherland_region
{
	LEFT = 1 << 0,
	RIGHT = 1 << 1,
	BOTTOM = 1 << 2,
	TOP = 1 << 3,
};

// Clamp v to [1, w - 1], [1, h - 1], it makes the
// fdf_draw_segment_quality easier to implement
int	cohen_sutherland_region(t_vec2 *v, int w, int h)
{
	int	region;

	region = 0;
	if (v->x < 1)
		region |= LEFT;
	else if (v->x >= w - 1)
		region |= RIGHT;
	if (v->y < 1)
		region |= BOTTOM;
	else if (v->y >= h - 1)
		region |= TOP;
	return (region);
}

int	cohen_sutherland(t_vec2 *s[2], int w, int h)
{
	int	region[2];
	int	outside;

	region[0] = cohen_sutherland_region(s[0], w, h);
	region[1] = cohen_sutherland_region(s[1], w, h);
	if ((region[0] | region[1]) == 0)
		return (1);
	if ((region[0] & region[1]) != 0)
		return (0);
	if (region[0] > region[1])
		outside = 0;
	else
		outside = 1;
	if (region[outside] & LEFT)
		*s[outside] = (t_vec2){1, intersect_segment_y(s, 1)};
	else if (region[outside] & RIGHT)
		*s[outside] = (t_vec2){w - 2, intersect_segment_y(s, w - 2)};
	else if (region[outside] & BOTTOM)
		*s[outside] = (t_vec2){intersect_segment_x(s, 1), 1};
	else if (region[outside] & TOP)
		*s[outside] = (t_vec2){intersect_segment_x(s, h - 2), h - 2};
	return (cohen_sutherland(s, w, h));
}
