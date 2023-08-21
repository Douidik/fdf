/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuppan <jsuppan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 20:02:25 by jsuppan           #+#    #+#             */
/*   Updated: 2023/08/21 21:25:39 by jsuppan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "interface.h"
#include "map.h"
#include "nav.h"
#include "palette.h"
#include "render/renderer.h"
#include "window.h"
#include <X11/keysym.h>
#include <ft_printf.h>
#include <math.h>
#include <mlx.h>

int	fdf_on_keypress(int k, t_fdf *fdf)
{
	int	used;

	used = 0;
	if (k == XK_Escape)
		used |= fdf_on_close(fdf);
	used |= fdf_pals_on_keypress(k, fdf);
	used |= fdf_camera_on_keypress(k, fdf);
	used |= fdf_nav_on_keypress(k, fdf);
	used |= fdf_render_on_keypress(k, fdf);
	return (used);
}

int	fdf_on_update(t_fdf *fdf)
{
	t_vec2	interface_rect[2];

	fdf_camera_nav(&fdf->cam, fdf->wnd, &fdf->nav);
	fdf_render_clear(fdf->render);
	fdf_draw_map(fdf->render, &fdf->cam, fdf->map);
	fdf_draw_nav(fdf->render, &fdf->nav);
	interface_rect[0] = (t_vec2){0, 0};
	interface_rect[1] = (t_vec2){fdf->wnd->w / 5, fdf->wnd->h};
	fdf_draw_rect(fdf->render, interface_rect,
		(t_fdf_color){.v = 0x64191919});
	fdf_render_present(fdf->render);
	fdf_interface_update(fdf->interface, fdf);
	return (0);
}

int	fdf_on_exposed(t_fdf *fdf)
{
	fdf_renderer_free(fdf->render);
	fdf->render = fdf_renderer_new(fdf->mlx, fdf);
	fdf->cam.obsolete = 1;
	return (0);
}

int	fdf_on_close(t_fdf *fdf)
{
	mlx_loop_end(fdf->mlx);
	return (1);
}
