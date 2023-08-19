#include "interface.h"
#include "fdf.h"
#include "render/renderer.h"
#include "util/mem.h"
#include "window.h"
#include <libft.h>
#include <mlx.h>
#include <stdlib.h>

t_fdf_interface *fdf_interface_new(struct s_fdf *fdf)
{
	t_fdf_interface *interface;

	interface = ft_calloc(1, sizeof(t_fdf_interface));
	if (!interface)
		return (NULL);
	interface->fdf = fdf;
	return (interface);
}

t_fdf_interface *fdf_interface_free(t_fdf_interface *interface)
{
	if (interface != NULL)
	{
		free(interface);
	}
	return (NULL);
}

void fdf_interface_draw(t_fdf_interface *interface, const char *s)
{
	t_fdf *fdf;
	t_fdf_window *wnd;

	fdf = interface->fdf;
	wnd = interface->fdf->wnd;
	mlx_string_put(fdf->mlx, wnd->impl, interface->pos.x, interface->pos.y, FDF_PAL_TEXT.v, (char *)s);
	interface->pos.x += interface->step.x;
	interface->pos.y += interface->step.y;
}

void fdf_interface_controls(t_fdf_interface *interface)
{
	fdf_interface_draw(interface, "> Controls");
	fdf_interface_draw(interface, "[Q] Orbit");
	fdf_interface_draw(interface, "[W] Pan");
	fdf_interface_draw(interface, "[E] Zoom");
	fdf_interface_draw(interface, "[S] Fly up/down");
	fdf_interface_draw(interface, "");
	fdf_interface_draw(interface, "[1]..[6]: Choose palette");
	fdf_interface_draw(interface, "[7] Perspective");
	fdf_interface_draw(interface, "[8] Orthographic");
	fdf_interface_draw(interface, "[9] Isometric");
	fdf_interface_draw(interface, "");
	fdf_interface_draw(interface, "[Mouse scroll] Map height");
}

void fdf_interface_update(t_fdf_interface *interface, t_fdf *fdf)
{
	char pal[64];
	char cam_proj[64];

	fdf->interface->pos = (t_vec2){10, 25};
	fdf->interface->step = (t_vec2){0, 25};
	fdf_interface_draw(interface, "> fdf - wireframe map renderer");
	fdf_interface_draw(interface, fdf->filename);
	fdf_interface_draw(interface, "");
	fdf_memset(pal, 0, sizeof(pal));
	ft_strlcat(pal, "Color palette [", sizeof(pal));
	ft_strlcat(pal, fdf->pals[fdf->pal].name, sizeof(pal));
	ft_strlcat(pal, "]", sizeof(pal));
	fdf_memset(cam_proj, 0, sizeof(cam_proj));
	ft_strlcat(cam_proj, "Camera projection: ", sizeof(cam_proj));
	ft_strlcat(cam_proj, fdf_camera_projection_name(fdf->cam.proj), sizeof(cam_proj));
	fdf_interface_draw(interface, cam_proj);
	fdf_interface_draw(interface, pal);
	if (fdf->render->render_mode == FDF_RENDER_FAST)
		fdf_interface_draw(interface, "Render mode: fast");
	if (fdf->render->render_mode == FDF_RENDER_QUALITY)
		fdf_interface_draw(interface, "Render mode: quality");
	fdf_interface_draw(interface, "");
	fdf_interface_controls(interface);
}
