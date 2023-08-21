/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuppan <jsuppan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 20:09:47 by jsuppan           #+#    #+#             */
/*   Updated: 2023/08/21 16:33:47 by jsuppan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "palette.h"
#include "fdf.h"
#include "util/mem.h"
#include <X11/keysym.h>
#include <stdlib.h>

t_fdf_color	hex(int v)
{
	return ((t_fdf_color){.v = v});
}

void	fdf_pals_init(t_fdf *fdf)
{
	fdf->pals[0] = (t_fdf_palette){0, "map", 0, {}};
	fdf->pals[1] = (t_fdf_palette){1, "ocean", 5, {
		hex(0xff023e8a), hex(0xff0077b6),
		hex(0xff0096c7), hex(0xff00b4d8),
		hex(0xff90e0ef)}};
	fdf->pals[2] = (t_fdf_palette){1, "light", 5, {
		hex(0xff3B786B), hex(0xff448EAC),
		hex(0xff617ACD), hex(0xff9F89E2),
		hex(0xffE2B7F2)}};
	fdf->pals[3] = (t_fdf_palette){1, "pastel", 5, {
		hex(0xfff08080), hex(0xfff4978e),
		hex(0xfff8ad9d), hex(0xfffbc4ab),
		hex(0xffffdab9)}};
	fdf->pals[4] = (t_fdf_palette){1, "cold", 7, {
		hex(0xffabc4ff), hex(0xffb6ccfe),
		hex(0xffc1d3fe), hex(0xffccdbfd),
		hex(0xffd7e3fc), hex(0xffe2eafc),
		hex(0xffedf2fb)}};
	fdf->pals[5] = (t_fdf_palette){1, "warm", 6, {
		hex(0xffff7b00), hex(0xffff9500),
		hex(0xffffa200), hex(0xffffb700),
		hex(0xffffd000), hex(0xffffea00)}};
	fdf->pal = 3;
}

int	fdf_pals_on_keypress(int k, t_fdf *fdf)
{
	if (k >= XK_1 && k <= XK_6)
	{
		fdf->pal = k - XK_1;
		fdf->cam.obsolete = 1;
		return (1);
	}
	return (0);
}
