#include "fdf.h"
#include "interface.h"
#include "map.h"
#include "palette.h"
#include "render/renderer.h"
#include "window.h"
#include <X11/Xlib.h>
#include <ft_printf.h>
#include <libft.h>
#include <math.h>
#include <mlx.h>
#include <stdlib.h>

const char *fdf_filename(const char *fp);

t_fdf *fdf_new(t_fdf_map *map, const char *fp)
{
	t_fdf *fdf;

	fdf = ft_calloc(1, sizeof(t_fdf));
	if (!fdf)
		return (NULL);
	fdf->filename = fdf_filename(fp);
	fdf->map = map;
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		return (ft_printf("cannot initialize mlx\n"), fdf_free(fdf));
	fdf->wnd = fdf_window_new(fdf->mlx, 1000, 800, "fdf");
	if (!fdf->wnd)
		return (ft_printf("cannot open window\n"), fdf_free(fdf));
	fdf->nav = fdf_nav_none();
	fdf->cam = fdf_camera_new(fdf->map, fdf->wnd);
	fdf->render = fdf_renderer_new(fdf->mlx, fdf);
	if (!fdf->render)
		return (ft_printf("cannot create renderer\n"), fdf_free(fdf));
	fdf->interface = fdf_interface_new(fdf);
	if (!fdf->interface)
		return (ft_printf("cannot create interface\n"), fdf_free(fdf));
	fdf_pals_init(fdf);
	return (fdf);
}

t_fdf *fdf_free(t_fdf *fdf)
{
	if (fdf != NULL)
	{
		if (fdf->interface != NULL)
			fdf_interface_free(fdf->interface);
		if (fdf->render != NULL)
			fdf_renderer_free(fdf->render);
		if (fdf->wnd != NULL)
			fdf_window_free(fdf->wnd);
		if (fdf->mlx != NULL)
			mlx_destroy_display(fdf->mlx);
		free(fdf);
	}
	return (NULL);
}

void fdf_run(t_fdf *fdf)
{
	mlx_do_key_autorepeatoff(fdf->mlx);
	mlx_hook(fdf->wnd->impl, KeyPress, KeyPressMask, &fdf_on_keypress, fdf);
	mlx_hook(fdf->wnd->impl, KeyRelease, KeyReleaseMask, &fdf_nav_on_keyrelease, fdf);
	mlx_hook(fdf->wnd->impl, ButtonPress, ButtonPressMask, &fdf_map_on_mouse, fdf);
	/* mlx_hook(fdf->wnd->impl, Expose, ExposureMask, &fdf_on_exposed, fdf); */
	mlx_loop_hook(fdf->mlx, &fdf_on_update, fdf);
	mlx_loop(fdf->mlx);
}

const char *fdf_filename(const char *fp)
{
	const char *filename;

	filename = fp;
	while (*fp != 0)
	{
		if (*fp == '/' || *fp == '\\')
			filename = fp + 1;
		fp++;
	}
	return (filename);
}
