/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_segment_quality.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuppan <jsuppan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 21:00:05 by jsuppan           #+#    #+#             */
/*   Updated: 2023/08/21 20:48:14 by jsuppan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math/cohen_sutherland.h"
#include "renderer.h"
#include "util/cmp.h"
#include "window.h"
#include <math.h>

typedef struct s_fdf_segment
{
	int				steep;
	int				x;
	int				x0;
	int				x1;
	float			y;
	float			slope;
	t_vec2f			d;
	t_fdf_shader	*shader;
	void			*data;
}	t_fdf_segment;

void	fdf_swap(int *v, int *w)
{
	int	tmp;

	tmp = *v;
	*v = *w;
	*w = tmp;
}

float	fdf_dec_part(float f)
{
	if (f > 0)
		return (f - ((int)f));
	else
		return (f - ((int)f + 1));
}

#define AA_FACTOR (1.3)

void	fdf_segment_trace(t_fdf_renderer *render, t_fdf_segment s)
{
	t_fdf_color	color;

	while (s.x <= s.x1)
	{
		if (s.steep)
			color = s.shader((t_vec2){s.y, s.x}, s.x - s.x0, s.d.x, s.data);
		else
			color = s.shader((t_vec2){s.x, s.y}, s.x - s.x0, s.d.x, s.data);
		if (color.a != 0)
		{
			color.a = (fminf(fdf_dec_part(s.y) * AA_FACTOR * 255, 255));
			if (s.steep && color.a != 0)
				fdf_draw_pixel(render, (t_vec2){s.y, s.x}, color);
			else if (color.a != 0)
				fdf_draw_pixel(render, (t_vec2){s.x, s.y}, color);
			color.a = (fminf((1 - fdf_dec_part(s.y)) * AA_FACTOR * 255, 255));
			if (s.steep && color.a != 0)
				fdf_draw_pixel(render, (t_vec2){s.y - 1, s.x}, color);
			else if (s.y - 1 > 0 && color.a != 0)
				fdf_draw_pixel(render, (t_vec2){s.x, s.y - 1}, color);
		}
		s.y += s.slope;
		s.x++;
	}
}

void	fdf_draw_segment_quality(t_fdf_renderer *render,
	t_vec2 p[2], t_fdf_shader shader, void *data)
{
	t_fdf_segment	s;

	if (!cohen_sutherland((t_vec2 *[2]){&p[0], &p[1]}, render->wnd->w,
		render->wnd->h))
		return ;
	s = (t_fdf_segment){.shader = shader, .data = data, .slope = 1};
	s.steep = fdf_abs(p[1].y - p[0].y) > fdf_abs(p[1].x - p[0].x);
	if (s.steep)
	{
		fdf_swap(&p[0].x, &p[0].y);
		fdf_swap(&p[1].x, &p[1].y);
	}
	if (p[0].x > p[1].x)
	{
		fdf_swap(&p[0].x, &p[1].x);
		fdf_swap(&p[0].y, &p[1].y);
	}
	s.d = (t_vec2f){p[1].x - p[0].x, p[1].y - p[0].y};
	if (s.d.x != 0.0)
		s.slope = s.d.y / s.d.x;
	s.x = p[0].x;
	s.y = p[0].y;
	s.x0 = p[0].x;
	s.x1 = p[1].x;
	fdf_segment_trace(render, s);
}
