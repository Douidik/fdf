/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_segment_fast.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuppan <jsuppan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 21:04:55 by jsuppan           #+#    #+#             */
/*   Updated: 2023/08/19 21:16:38 by jsuppan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math/cohen_sutherland.h"
#include "renderer.h"
#include "window.h"
#include <math.h>

void	fdf_draw_segment_fast(t_fdf_renderer *render,
	t_vec2 p[2], t_fdf_shader shader, void *data)
{
	t_vec2f		d;
	t_vec2f		v;
	int			len;
	int			i;
	t_fdf_color	color;

	if (!cohen_sutherland((t_vec2 *[2]){&p[0], &p[1]},
		render->wnd->w, render->wnd->h))
		return ;
	d = (t_vec2f){p[1].x - p[0].x, p[1].y - p[0].y};
	v = (t_vec2f){p[0].x, p[0].y};
	len = fmaxf(fabsf(d.x), fabsf(d.y));
	if (len != 0)
	{
		d.x /= len;
		d.y /= len;
	}
	i = 0;
	while (i < len)
	{
		color = shader((t_vec2){v.x, v.y}, i, len, data);
		fdf_draw_pixel(render, (t_vec2){v.x, v.y}, color);
		v = (t_vec2f){.x = v.x + d.x, .y = v.y + d.y};
		i++;
	}
}
