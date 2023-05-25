#include "camera.h"
#include "nav.h"
#include "window.h"
#include <math.h>
#include <float.h>

#define FDF_MOUSE_SENSITIVITY (0.3f)

void fdf_camera_move(t_fdf_camera *cam, t_fdf_nav *nav, t_vec2f motion)
{
	if (motion.x == 0 && motion.y == 0)
		return;
	cam->pos.x = nav->prev.x + motion.x;
	cam->pos.y = nav->prev.y;
	cam->pos.z = nav->prev.z + motion.y;
	cam->obsolete = 1;
}

void fdf_camera_look(t_fdf_camera *cam, t_fdf_nav *nav, t_vec2f motion)
{
	if (motion.x == 0 && motion.y == 0)
		return;
	cam->rot.x = nav->prev.x + motion.y * M_PI / 180;
	cam->rot.y = nav->prev.y + motion.x * M_PI / 180;
	cam->rot.z = nav->prev.z;
	cam->obsolete = 1;
}

void fdf_camera_zoom(t_fdf_camera *cam, t_fdf_nav *nav, t_vec2f motion)
{
	float amount;

	amount = motion.x * motion.x + motion.y * motion.y;
	if (amount == 0)
		return;
	cam->scale.x = fmaxf(nav->prev.x + amount, 0.0);
	cam->scale.y = fmaxf(nav->prev.y + amount, 0.0);
	cam->scale.z = fmaxf(nav->prev.z + amount, 0.0);
	cam->obsolete = 1;
}

void fdf_camera_nav(t_fdf_camera *cam, t_fdf_window *wnd, t_fdf_nav *nav)
{
	t_vec2 mouse;
	t_vec2f motion;

	if (nav->type == FDF_NAV_IDLE)
		return;
	mouse = fdf_window_mouse_get(wnd);
	motion.x = (nav->anchor.x - mouse.x) * FDF_MOUSE_SENSITIVITY;
	motion.y = (nav->anchor.y - mouse.y) * FDF_MOUSE_SENSITIVITY;
	if (nav->type == FDF_NAV_MOVE)
		fdf_camera_move(cam, nav, motion);
	else if (nav->type == FDF_NAV_LOOK)
		fdf_camera_look(cam, nav, motion);
	else if (nav->type == FDF_NAV_ZOOM)
		fdf_camera_zoom(cam, nav, motion);
}
