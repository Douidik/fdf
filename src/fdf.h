#ifndef FDF_FDF_H
#define FDF_FDF_H

#include "camera.h"
#include "nav.h"
#include "palette.h"

typedef struct s_fdf
{
	void *mlx;
	const char *filename;
	struct s_fdf_map *map;
	struct s_fdf_window *wnd;
	struct s_fdf_renderer *render;
	struct s_fdf_interface *interface;
	t_fdf_nav nav;
	t_fdf_camera cam;
	t_fdf_palette pals[6];
	size_t pal;
} t_fdf;

t_fdf *fdf_new(struct s_fdf_map *map, const char *fp);
t_fdf *fdf_free(t_fdf *fdf);
void fdf_run(t_fdf *fdf);

int fdf_on_keypress(int k, t_fdf *fdf);
int fdf_on_update(t_fdf *fdf);
int fdf_on_exposed(t_fdf *fdf);

#endif
