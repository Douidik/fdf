/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_segment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuppan <jsuppan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 20:59:31 by jsuppan           #+#    #+#             */
/*   Updated: 2023/08/19 21:00:01 by jsuppan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"
#include <math.h>
#include <mlx.h>
#include <stdbool.h>

void	fdf_draw_segment(t_fdf_renderer *render, t_vec2 p[2],
			t_fdf_shader shader, void *data)
{
	if (render->render_mode == FDF_RENDER_FAST)
		fdf_draw_segment_fast(render, p, shader, data);
	if (render->render_mode == FDF_RENDER_QUALITY)
		fdf_draw_segment_quality(render, p, shader, data);
}
