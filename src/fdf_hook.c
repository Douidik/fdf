#include "fdf.h"
#include "nav.h"
#include "render/renderer.h"
#include "window.h"
#include <X11/keysym.h>
#include <mlx.h>

int fdf_on_keypress(int k, t_fdf *fdf)
{
	if (k == XK_Escape)
		return (mlx_loop_end(fdf->mlx), 1);
	fdf_nav_on_keypress(fdf, k);
	return (0);
}

int fdf_on_keyrelease(int k, t_fdf *fdf)
{
	fdf_nav_on_keyrelease(fdf, k);
	return (0);
}

int fdf_on_update(t_fdf *fdf)
{
	fdf_camera_nav(&fdf->cam, fdf->wnd, &fdf->nav);
	if (fdf->cam.obsolete)
	{
		fdf_render_clear(fdf->render);
		fdf_draw_map(fdf->render, &fdf->cam, fdf->map);
		fdf_draw_nav(fdf->render, &fdf->nav);
	}
	fdf_render_present(fdf->render);
	return (0);
}
