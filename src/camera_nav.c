/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_nav.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuppan <jsuppan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 19:59:34 by jsuppan           #+#    #+#             */
/*   Updated: 2023/08/19 20:39:37 by jsuppan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "nav.h"
#include "window.h"
#include <math.h>

#define FDF_ORBIT_SPEED (M_2_PI)
#define FDF_PAN_SPEED (0.25)
#define FDF_ZOOM_SPEED (M_PI)

void	fdf_camera_nav_orbit(t_fdf_camera *cam, t_fdf_camera *prev,
		t_vec2f motion)
{
	float	move_azimuth;
	float	move_polar;
	float	azimuth;
	float	polar;

	if (motion.x != 0 || motion.y != 0)
	{
		move_azimuth = motion.x * FDF_ORBIT_SPEED / cam->wnd->w;
		move_polar = motion.y * FDF_ORBIT_SPEED / cam->wnd->h;
		azimuth = prev->azimuth - move_azimuth;
		polar = prev->polar + move_polar;
		azimuth = fmodf(fmodf(azimuth, +M_PI * 2), -M_PI * 2);
		polar = fminf(fmaxf(polar, -M_PI / 2), +M_PI / 2);
		fdf_camera_orbit(cam, polar, azimuth);
		cam->obsolete = 1;
	}
}

void	fdf_camera_nav_pan(t_fdf_camera *cam, t_fdf_camera *prev,
		t_vec2f motion)
{
	t_vec3f	move;

	if (motion.x != 0 || motion.y != 0)
	{
		move.x = cosf(cam->rot.y + M_PI_2) * motion.y
			+ cosf(cam->rot.y) * motion.x;
		move.z = sinf(cam->rot.y + M_PI_2) * motion.y
			+ sinf(cam->rot.y) * motion.x;
		cam->pan.x = prev->pan.x + move.x * FDF_PAN_SPEED;
		cam->pan.z = prev->pan.z + move.z * FDF_PAN_SPEED;
		cam->obsolete = 1;
	}
}

void	fdf_camera_nav_zoom(t_fdf_camera *cam, t_fdf_camera *prev,
	t_vec2f motion)
{
	float	amount;

	amount = motion.y * FDF_ZOOM_SPEED / cam->wnd->h;
	if (amount != 0)
	{
		cam->plane.zoom = fmax(prev->plane.zoom + amount, 0);
		cam->obsolete = 1;
	}
}

void	fdf_camera_nav_fly(t_fdf_camera *cam, t_fdf_camera *prev,
		t_vec2f motion)
{
	if (motion.y != 0)
	{
		cam->pan.y = prev->pan.y + motion.y * FDF_PAN_SPEED;
		cam->obsolete = 1;
	}
}

void	fdf_camera_nav(t_fdf_camera *cam, t_fdf_window *wnd, t_fdf_nav *nav)
{
	t_vec2	mouse;
	t_vec2f	motion;

	if (nav->type == FDF_NAV_NONE)
		return ;
	mouse = fdf_window_mouse_get(wnd);
	motion.x = (nav->anchor.x - mouse.x);
	motion.y = (nav->anchor.y - mouse.y);
	if (nav->type == FDF_NAV_ORBIT)
		fdf_camera_nav_orbit(cam, &nav->prev, motion);
	else if (nav->type == FDF_NAV_PAN)
		fdf_camera_nav_pan(cam, &nav->prev, motion);
	else if (nav->type == FDF_NAV_ZOOM)
		fdf_camera_nav_zoom(cam, &nav->prev, motion);
	else if (nav->type == FDF_NAV_FLY)
		fdf_camera_nav_fly(cam, &nav->prev, motion);
}
