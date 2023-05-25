#include "fdf.h"
#include "map.h"
#include "render/renderer.h"
#include "window.h"
#include <ft_printf.h>
#include <libft.h>
#include <mlx.h>
#include <stdlib.h>
#include <X11/Xlib.h>

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
	fdf->wnd = fdf_window_new(fdf->mlx, 800, 800, fdf->filename);
	if (!fdf->wnd)
		return (ft_printf("cannot open window\n"), fdf_free(fdf));
	fdf->nav = fdf_nav_new();
	fdf->cam = fdf_camera_new(90, fdf->wnd);
	fdf->tab = FDF_TAB_HELP;
	fdf->render = fdf_renderer_new(fdf->mlx, fdf->wnd, fdf->map);
	if (!fdf->render)
		return (ft_printf("cannot create renderer\n"), fdf_free(fdf));
	return (fdf);
}

t_fdf *fdf_free(t_fdf *fdf)
{
	if (fdf != NULL)
	{
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
	mlx_hook(fdf->wnd->impl, KeyRelease, KeyReleaseMask, &fdf_on_keyrelease, fdf);
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
