#include "palette.h"
#include "fdf.h"
#include "util/mem.h"
#include <X11/keysym.h>
#include <stdlib.h>

void fdf_pals_init(t_fdf *fdf)
{
	fdf->pals[0] = (t_fdf_palette){0, "map", 0, {}};
	fdf->pals[1] = (t_fdf_palette){1, "ocean", 5, {fdf_color_hex(0xff023e8a), fdf_color_hex(0xff0077b6), fdf_color_hex(0xff0096c7), fdf_color_hex(0xff00b4d8), fdf_color_hex(0xff90e0ef)}};
	fdf->pals[2] = (t_fdf_palette){1, "light", 5, {fdf_color_hex(0xff3B786B), fdf_color_hex(0xff448EAC), fdf_color_hex(0xff617ACD), fdf_color_hex(0xff9F89E2), fdf_color_hex(0xffE2B7F2)}};
	fdf->pals[3] = (t_fdf_palette){1, "pastel", 5, {fdf_color_hex(0xfff08080), fdf_color_hex(0xfff4978e), fdf_color_hex(0xfff8ad9d), fdf_color_hex(0xfffbc4ab), fdf_color_hex(0xffffdab9)}};
	fdf->pals[4] = (t_fdf_palette){1, "cold", 7, {fdf_color_hex(0xffabc4ff), fdf_color_hex(0xffb6ccfe), fdf_color_hex(0xffc1d3fe), fdf_color_hex(0xffccdbfd), fdf_color_hex(0xffd7e3fc), fdf_color_hex(0xffe2eafc), fdf_color_hex(0xffedf2fb)}};
	fdf->pals[5] = (t_fdf_palette){1, "warm", 6, {fdf_color_hex(0xffff7b00), fdf_color_hex(0xffff9500), fdf_color_hex(0xffffa200), fdf_color_hex(0xffffb700), fdf_color_hex(0xffffd000), fdf_color_hex(0xffffea00)}};
	fdf->pal = 3;
}

int fdf_pals_on_keypress(int k, t_fdf *fdf)
{
	if (k >= XK_1 && k <= XK_6)
	{
		fdf->pal = k - XK_1;
		fdf->cam.obsolete = 1;
		return (1);
	}
	return (0);
}
