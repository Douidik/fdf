/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuppan <jsuppan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 21:16:47 by jsuppan           #+#    #+#             */
/*   Updated: 2023/08/19 21:17:17 by jsuppan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"
#include "window.h"
#include <assert.h>

void	fdf_draw_pixel(t_fdf_renderer *render, t_vec2 pos, t_fdf_color src)
{
	t_fdf_color	*dst;
	float		alpha;

	dst = (t_fdf_color *)
		(render->stream + pos.y * render->sw + pos.x *(render->bpp / 8));
	if (src.a == 0)
		return ;
	if (src.a != 255)
	{
		alpha = (float)src.a / 255;
		dst->r = ((1.0 - alpha) * dst->r) + (alpha * src.r);
		dst->g = ((1.0 - alpha) * dst->g) + (alpha * src.g);
		dst->b = ((1.0 - alpha) * dst->b) + (alpha * src.b);
	}
	else
	{
		dst->v = src.v;
		dst->a = 255;
	}
}
