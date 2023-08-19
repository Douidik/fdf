/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_nav.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuppan <jsuppan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 21:17:20 by jsuppan           #+#    #+#             */
/*   Updated: 2023/08/19 21:17:27 by jsuppan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nav.h"
#include "renderer.h"
#include "window.h"
#include <stddef.h>

t_fdf_color	fdf_nav_shader(t_vec2 pos, int n, int len, void *data)
{
	(void)pos;
	(void)data;
	(void)len;
	if (n % 12 < 6)
		return ((t_fdf_color){.v = 0xffffffff});
	else
		return ((t_fdf_color){.v = 0x00000000});
}

void	fdf_draw_nav(t_fdf_renderer *render, t_fdf_nav *nav)
{
	t_vec2	s[2];

	if (nav->type != FDF_NAV_NONE)
	{
		s[0] = nav->anchor;
		s[1] = fdf_window_mouse_get(render->wnd);
		fdf_draw_segment(render, s, fdf_nav_shader, NULL);
	}
}
