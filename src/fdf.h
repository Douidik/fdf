#ifndef FDF_FDF_H
#define FDF_FDF_H

#include "camera.h"
#include "nav.h"

typedef enum e_fdf_tab
{
	FDF_TAB_HELP,
	FDF_TAB_DEBUG,
	FDF_TAB_CINEMATIC,
	FDF_TAB_COUNT,
} t_fdf_tab;

typedef struct s_fdf
{
	void *mlx;
	const char *filename;
	struct s_fdf_map *map;
	struct s_fdf_window *wnd;
	struct s_fdf_renderer *render;
	t_fdf_nav nav;
	t_fdf_camera cam;
	t_fdf_tab tab;
} t_fdf;

t_fdf *fdf_new(struct s_fdf_map *map, const char *fp);
t_fdf *fdf_free(t_fdf *fdf);
void fdf_run(t_fdf *fdf);

int fdf_on_update(t_fdf *fdf);
int fdf_on_keypress(int k, t_fdf *fdf);
int fdf_on_keyrelease(int k, t_fdf *fdf);

#endif
