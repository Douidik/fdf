#include "nav.h"
#include "fdf.h"
#include "window.h"
#include <X11/keysym.h>
#include <mlx.h>

t_fdf_nav fdf_nav_new(void)
{
	return (t_fdf_nav){
		.type = FDF_NAV_IDLE,
		.prev = (t_vec3f){0},
		.anchor = (t_vec2){0},
		.k = 0,
	};
}

void fdf_nav_begin(t_fdf *fdf, int k, t_fdf_nav_input_type type, t_vec3f prev)
{
	fdf->nav = (t_fdf_nav){
		.prev = prev,
		.anchor = fdf_window_mouse_get(fdf->wnd),
		.type = type,
		.k = k,
	};
	mlx_mouse_hide(fdf->mlx, fdf->wnd->impl);
	fdf->cam.obsolete = 1;
}

void fdf_nav_on_keypress(t_fdf *fdf, int k)
{
	if (k == XK_q)
		fdf_nav_begin(fdf, k, FDF_NAV_MOVE, fdf->cam.pos);
	else if (k == XK_w)
		fdf_nav_begin(fdf, k, FDF_NAV_LOOK, fdf->cam.rot);
	else if (k == XK_e)
		fdf_nav_begin(fdf, k, FDF_NAV_ZOOM, fdf->cam.scale);
}

void fdf_nav_on_keyrelease(t_fdf *fdf, int k)
{
	if (k != fdf->nav.k)
		return;
	mlx_mouse_show(fdf->mlx, fdf->wnd->impl);
	fdf->nav = fdf_nav_new();
	fdf->cam.obsolete = 1;
}
