/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nav.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuppan <jsuppan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 20:08:55 by jsuppan           #+#    #+#             */
/*   Updated: 2023/08/19 20:09:07 by jsuppan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nav.h"
#include "fdf.h"
#include "window.h"
#include <X11/keysym.h>
#include <mlx.h>

t_fdf_nav	fdf_nav_none(void)
{
	return ((t_fdf_nav){
		.type = FDF_NAV_NONE,
		.anchor = (t_vec2){0},
		.k = 0,
	});
}

int	fdf_nav_begin(t_fdf *fdf, int k, t_fdf_nav_input_type type)
{
	fdf->nav = (t_fdf_nav){
		.anchor = fdf_window_mouse_get(fdf->wnd),
		.type = type,
		.prev = fdf->cam,
		.k = k,
	};
	fdf->cam.obsolete = 1;
	return (1);
}

int	fdf_nav_on_keypress(int k, t_fdf *fdf)
{
	if (k == XK_q && fdf->cam.proj != FDF_CAM_ISOMETRIC)
		return (fdf_nav_begin(fdf, k, FDF_NAV_ORBIT));
	else if (k == XK_w)
		return (fdf_nav_begin(fdf, k, FDF_NAV_PAN));
	else if (k == XK_e)
		return (fdf_nav_begin(fdf, k, FDF_NAV_ZOOM));
	else if (k == XK_s)
		return (fdf_nav_begin(fdf, k, FDF_NAV_FLY));
	return (0);
}

int	fdf_nav_on_keyrelease(int k, t_fdf *fdf)
{
	if (k != fdf->nav.k)
		return (0);
	mlx_mouse_show(fdf->mlx, fdf->wnd->impl);
	fdf->nav = fdf_nav_none();
	fdf->cam.obsolete = 1;
	return (1);
}
