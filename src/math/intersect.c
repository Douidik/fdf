/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuppan <jsuppan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 21:26:12 by jsuppan           #+#    #+#             */
/*   Updated: 2023/08/19 21:26:42 by jsuppan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersect.h"

// From: https://en.wikipedia.org/wiki/Cohen%E2%80%93Sutherland_algorithm
// slope = (y1 - y0) / (x1 - x0)
// slope = (b->y - a->y) / (b->x - a->x)
// y = y0 + slope * (xm - x0), where xm is xmin or xmax

float	segment_slope(t_vec2 *s[2])
{
	return ((float)(s[1]->y - s[0]->y) / (s[1]->x - s[0]->x));
}

int	intersect_segment_x(t_vec2 *s[2], int y)
{
	return (s[0]->x + (1 / segment_slope(s)) * (y - s[0]->y));
}

int	intersect_segment_y(t_vec2 *s[2], int x)
{
	return (s[0]->y + segment_slope(s) * (x - s[0]->x));
}
