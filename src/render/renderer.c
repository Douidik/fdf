#include "renderer.h"
#include "map.h"
#include "util/mem.h"
#include "window.h"
#include <libft.h>
#include <math.h>
#include <mlx.h>
#include <stdlib.h>

t_fdf_renderer *fdf_renderer_new(void *mlx, struct s_fdf_window *wnd, struct s_fdf_map *map)
{
	t_fdf_renderer *render;

	render = ft_calloc(1, sizeof(t_fdf_renderer));
	if (!render)
		return (NULL);
	render->mlx = mlx;
	render->wnd = wnd;
	render->image = mlx_new_image(mlx, wnd->w, wnd->h);
	if (!render->image)
		return (fdf_renderer_free(render));
	render->stream = (uint8_t *)mlx_get_data_addr(render->image, &render->bpp, &render->sw, (int *)&render->endian);
	if (!render->stream)
		return (fdf_renderer_free(render));
	render->vs = ft_calloc(map->w * map->h, sizeof(t_fdf_vertex));
	if (!render->vs)
		return (fdf_renderer_free(render));
	render->zbuffer = ft_calloc(wnd->w * wnd->h, sizeof(float));
	if (!render->zbuffer)
		return (fdf_renderer_free(render));
	return (render);
}
t_fdf_renderer *fdf_renderer_free(t_fdf_renderer *render)
{
	if (render != NULL)
	{
		if (render->vs != NULL)
			free(render->vs);
		if (render->zbuffer != NULL)
			free(render->zbuffer);
		if (render->image != NULL)
			mlx_destroy_image(render->mlx, render->image);
		free(render);
	}
	return (NULL);
}

void fdf_render_clear(t_fdf_renderer *render)
{
	size_t i;

	i = 0;
	while (i < render->wnd->w * render->wnd->h)
		render->zbuffer[i++] = INFINITY;
	fdf_memset(render->stream, 0, render->wnd->w * render->wnd->h * (render->bpp / 8));
}

void fdf_render_present(t_fdf_renderer *render)
{
	mlx_put_image_to_window(render->mlx, render->wnd->impl, render->image, 0, 0);
}
