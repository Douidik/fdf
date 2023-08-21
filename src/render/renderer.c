/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuppan <jsuppan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 20:57:26 by jsuppan           #+#    #+#             */
/*   Updated: 2023/08/21 20:06:24 by jsuppan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"
#include "fdf.h"
#include "map.h"
#include "util/mem.h"
#include "window.h"
#include <X11/keysym.h>
#include <libft.h>
#include <math.h>
#include <mlx.h>
#include <stdlib.h>

t_fdf_renderer	*fdf_renderer_new(void *mlx, t_fdf *fdf)
{
	t_fdf_renderer	*render;

	render = ft_calloc(1, sizeof(t_fdf_renderer));
	if (!render)
		return (NULL);
	render->mlx = mlx;
	render->fdf = fdf;
	render->wnd = fdf->wnd;
	render->image = mlx_new_image(mlx, fdf->wnd->w, fdf->wnd->h);
	if (!render->image)
		return (fdf_renderer_free(render));
	render->stream = (uint8_t *)mlx_get_data_addr(render->image,
			&render->bpp, &render->sw, (int *)&render->endian);
	if (!render->stream)
		return (fdf_renderer_free(render));
	render->vs = ft_calloc(fdf->map->w * fdf->map->h, sizeof(t_fdf_vertex));
	if (!render->vs)
		return (fdf_renderer_free(render));
	render->zbuffer = ft_calloc(fdf->wnd->w * fdf->wnd->h, sizeof(float));
	if (!render->zbuffer)
		return (fdf_renderer_free(render));
	return (render);
}

t_fdf_renderer	*fdf_renderer_free(t_fdf_renderer *render)
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

// This value is used to clear the z-buffer
// (+inf << 32) | (+inf)
#define FDF_ZBUF_INF (0x7f8000007f800000)

// The image is cleared to color (0f, 0f, 0f, 0f)
void	fdf_render_clear(t_fdf_renderer *render)
{
	fdf_memset64(render->zbuffer, FDF_ZBUF_INF,
		render->wnd->w * render->wnd->h * sizeof(float));
	fdf_memset(render->stream, 0x1f,
		render->wnd->w * render->wnd->h * (render->bpp / 8));
}

void	fdf_render_present(t_fdf_renderer *render)
{
	mlx_put_image_to_window(render->mlx,
		render->wnd->impl, render->image, 0, 0);
}

int	fdf_render_on_keypress(int k, t_fdf *fdf)
{
	t_fdf_renderer	*render;

	render = fdf->render;
	if (k == XK_r || k == XK_t)
	{
		if (k == XK_r)
			render->render_mode = FDF_RENDER_FAST;
		if (k == XK_t)
			render->render_mode = FDF_RENDER_QUALITY;
		fdf->cam.obsolete = 1;
		return (1);
	}
	return (0);
}
