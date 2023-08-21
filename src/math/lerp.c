/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lerp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuppan <jsuppan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 21:25:29 by jsuppan           #+#    #+#             */
/*   Updated: 2023/08/21 21:25:48 by jsuppan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lerp.h"
#include "render/color.h"

float	fdf_lerp(float t, float a, float b)
{
	return (a + t * (b - a));
}

t_fdf_color	fdf_lerp_rgb(float t, t_fdf_color a, t_fdf_color b)
{
	t_fdf_color	lerp;

	lerp.r = a.r + t * (b.r - a.r);
	lerp.g = a.g + t * (b.g - a.g);
	lerp.b = a.b + t * (b.b - a.b);
	lerp.a = 255;
	return (lerp);
}

t_fdf_color	fdf_lerp_rgbs(float t, t_fdf_color p[], size_t len)
{
	float	point_time;
	float	point_len;
	size_t	point_n;

	point_len = 1.0f / (len - 1);
	point_n = t / point_len;
	point_time = (t - point_n * point_len) / point_len;
	if (point_n < len - 1)
		return (fdf_lerp_rgb(point_time, p[point_n], p[point_n + 1]));
	else
		return (p[len - 1]);
}
