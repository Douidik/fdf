#ifndef FDF_PALETTE_H
#define FDF_PALETTE_H

#include "render/color.h"
#include <stddef.h>

struct s_fdf;

typedef struct s_fdf_palette
{
	int enabled;
	const char *name;
	size_t len;
	t_fdf_color colors[8];
} t_fdf_palette;

void fdf_pals_init(struct s_fdf *fdf);
int fdf_pals_on_keypress(int k, struct s_fdf *fdf);

#endif
