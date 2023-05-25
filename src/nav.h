#ifndef FDF_NAV_H
#define FDF_NAV_H

#include "math/vec.h"

struct s_fdf;

typedef enum e_fdf_nav_input_type
{
	FDF_NAV_IDLE,
	FDF_NAV_MOVE,
	FDF_NAV_LOOK,
	FDF_NAV_ZOOM,
} t_fdf_nav_input_type;

typedef struct s_fdf_nav
{
	t_fdf_nav_input_type type;
	t_vec3f prev;
	t_vec2 anchor;
	int k;
} t_fdf_nav;

t_fdf_nav fdf_nav_new(void);
void fdf_nav_on_keypress(struct s_fdf *fdf, int k);
void fdf_nav_on_keyrelease(struct s_fdf *fdf, int k);

#endif
