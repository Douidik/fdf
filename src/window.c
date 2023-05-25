#include "window.h"
#include <libft.h>
#include <mlx.h>
#include <stdlib.h>

t_fdf_window *fdf_window_new(void *mlx, int w, int h, const char *filename)
{
	t_fdf_window *wnd;

	wnd = ft_calloc(1, sizeof(t_fdf_window));
	if (!wnd)
		return (NULL);
	wnd->mlx = mlx;
	wnd->w = w;
	wnd->h = h;
	wnd->name = ft_strjoin("fdf - ", filename);
	if (!wnd->name)
		return (fdf_window_free(wnd));
	wnd->impl = mlx_new_window(mlx, w, h, wnd->name);
	return (wnd);
}

t_fdf_window *fdf_window_free(t_fdf_window *wnd)
{
	if (wnd != NULL)
	{
		if (wnd->name != NULL)
			free(wnd->name);
		if (wnd->impl != NULL)
			mlx_destroy_window(wnd->mlx, wnd->impl);
		free(wnd);
	}
	return (NULL);
}

t_vec2 fdf_window_mouse_get(t_fdf_window *wnd)
{
	int x;
	int y;

	mlx_mouse_get_pos(wnd->mlx, wnd->impl, &x, &y);
	return (t_vec2){x, y};
}

t_vec2 fdf_window_mouse_set(t_fdf_window *wnd, t_vec2 pos)
{
	mlx_mouse_move(wnd->mlx, wnd->impl, pos.x, pos.y);
	return (pos);
}
