#include "renderer.h"
#include <math.h>
#include <mlx.h>
#include <stdbool.h>

void fdf_draw_segment(t_fdf_renderer *render, t_vec2 p[2], t_fdf_shader shader, void *data)
{
	if (render->render_mode == FDF_RENDER_FAST)
		fdf_draw_segment_fast(render, p, shader, data);
	if (render->render_mode == FDF_RENDER_QUALITY)
		fdf_draw_segment_quality(render, p, shader, data);
}

/* void fdf_swap(int *v, int *w) */
/* { */
/* 	int tmp; */

/* 	tmp = *v; */
/* 	*v = *w; */
/* 	*w = tmp; */
/* } */

/* int fdf_int_part(float f) */
/* { */
/* 	return ((int)f); */
/* } */

/* float fdf_dec_part(float f) */
/* { */
/* 	if (f > 0) */
/* 		return (f - fdf_int_part(f)); */
/* 	else */
/* 		return (f - (fdf_int_part(f) + 1)); */
/* } */

/* float fdf_inv_dec_part(float f) */
/* { */
/* 	return (1 - fdf_dec_part(f)); */
/* } */

/* void fdf_plot(t_fdf_renderer *render, t_vec2 pos, t_fdf_color color, float a) */
/* { */
/* 	color.a = a * 255; */
/* 	fdf_draw_pixel(render, pos, color); */
/* } */

/* void fdf_draw_segment(t_fdf_renderer *render, t_vec2 s[2], t_fdf_shader shader, void *data) */
/* { */
/* 	if (!cohen_sutherland((t_vec2 *[2]){&s[0], &s[1]}, render->wnd->w, render->wnd->h)) */
/* 		return; */
/* 	int x0 = s[0].x, x1 = s[1].x; */
/* 	int y0 = s[0].y, y1 = s[1].y; */
/* 	bool steep = fdf_abs(y1 - y0) > fdf_abs(x1 - x0); */

/* 	// Swap the coordinates because the segment is backwards */
/* 	if (steep) */
/* 	{ */
/* 		fdf_swap(&x0, &y0); */
/* 		fdf_swap(&x1, &y1); */
/* 	} */
/* 	if (x0 > x1) */
/* 	{ */
/* 		fdf_swap(&x0, &x1); */
/* 		fdf_swap(&y0, &y1); */
/* 	} */

/* 	float dx = x1 - x0; */
/* 	float dy = y1 - y0; */
/* 	float gradient; */
/* 	if (dx != 0.0) */
/* 		gradient = dy / dx; */
/* 	else */
/* 		gradient = 1; */

/* 	float intersect_y = y0; */

/* 	if (steep) */
/* 	{ */
/* 		int x = x0; */
/* 		while (x <= x1) */
/* 		{ */
/* 			t_fdf_color color = shader((t_vec2){intersect_y, x}, x - x0, dx, data); */
/* 			fdf_plot(render, (t_vec2){intersect_y, x}, color, fdf_dec_part(intersect_y)); */
/* 			fdf_plot(render, (t_vec2){intersect_y - 1, x}, color, fdf_inv_dec_part(intersect_y)); */
/* 			intersect_y += gradient; */
/* 			x++; */
/* 		} */
/* 	} */
/* 	else */
/* 	{ */
/* 		int x = x0; */
/* 		while (x <= x1) */
/* 		{ */
/* 			t_fdf_color color = shader((t_vec2){x, intersect_y}, x - x0, dx, data); */
/* 			fdf_plot(render, (t_vec2){x, intersect_y}, color, fdf_dec_part(intersect_y)); */
/* 			fdf_plot(render, (t_vec2){x, intersect_y - 1}, color, fdf_inv_dec_part(intersect_y)); */
/* 			intersect_y += gradient; */
/* 			x++; */
/* 		} */
/* 	} */
/* } */

/* /\* void fdf_draw_segment(t_fdf_renderer *render, t_vec2 s[2], t_fdf_shader shader, void *data) *\/ */
/* /\* { *\/ */
/* /\* 	t_vec2f d; *\/ */
/* /\* 	t_vec2f v; *\/ */
/* /\* 	int len; *\/ */
/* /\* 	int i; *\/ */
/* /\* 	t_fdf_color color; *\/ */

/* /\* 	if (!cohen_sutherland((t_vec2 *[2]){&s[0], &s[1]}, render->wnd->w, render->wnd->h)) *\/ */
/* /\* 		return; *\/ */
/* /\* 	d.x = s[1].x - s[0].x; *\/ */
/* /\* 	d.y = s[1].y - s[0].y; *\/ */
/* /\* 	v = (t_vec2f){s[0].x, s[0].y}; *\/ */
/* /\* 	len = fmaxf(fabsf(d.x), fabsf(d.y)); *\/ */
/* /\* 	if (len != 0) *\/ */
/* /\* 	{ *\/ */
/* /\* 		d.x /= len; *\/ */
/* /\* 		d.y /= len; *\/ */
/* /\* 	} *\/ */
/* /\* 	i = 0; *\/ */
/* /\* 	while (i < len) *\/ */
/* /\* 	{ *\/ */
/* /\* 		color = shader((t_vec2){v.x, v.y}, i, len, data); *\/ */
/* /\* 		fdf_draw_pixel(render, (t_vec2){v.x, v.y}, color); *\/ */
/* /\* 		v.x += d.x; *\/ */
/* /\* 		v.y += d.y; *\/ */
/* /\* 		i++; *\/ */
/* /\* 	} *\/ */
/* /\* } *\/ */

/* // SAVE ! */

/* /\* void fdf_swap(int *v, int *w) *\/ */
/* /\* { *\/ */
/* /\* 	int tmp; *\/ */

/* /\* 	tmp = *v; *\/ */
/* /\* 	*v = *w; *\/ */
/* /\* 	*w = tmp; *\/ */
/* /\* } *\/ */

/* /\* int fdf_int_part(float f) *\/ */
/* /\* { *\/ */
/* /\* 	return ((int)f); *\/ */
/* /\* } *\/ */

/* /\* float fdf_dec_part(float f) *\/ */
/* /\* { *\/ */
/* /\* 	if (f > 0) *\/ */
/* /\* 		return (f - fdf_int_part(f)); *\/ */
/* /\* 	else *\/ */
/* /\* 		return (f - (fdf_int_part(f) + 1)); *\/ */
/* /\* } *\/ */

/* /\* float fdf_inv_dec_part(float f) *\/ */
/* /\* { *\/ */
/* /\* 	return (1 - fdf_dec_part(f)); *\/ */
/* /\* } *\/ */

/* /\* void fdf_plot(t_fdf_renderer *render, int x, int y, float f) *\/ */
/* /\* { *\/ */
/* /\* 	/\\* int c = (FDF_WHITE.v ^ (0xff << 24)) | ((int)(f * 255) << 24); *\\/ *\/ */
/* /\* 	/\\* mlx_pixel_put(render->mlx, render->wnd->impl, x, y, 0xffffff | a); *\\/ *\/ */
/* /\* 	int a = ((int)(f * 255) << 24) / 2; *\/ */
/* /\* 	fdf_draw_pixel(render, (t_vec2){x, y}, (t_fdf_color){.v = 0xffffff | a}); *\/ */
/* /\* } *\/ */

/* /\* void fdf_draw_segment(t_fdf_renderer *render, t_vec2 s[2], t_fdf_shader shader, void *data) *\/ */
/* /\* { *\/ */
/* /\* 	if (!cohen_sutherland((t_vec2 *[2]){&s[0], &s[1]}, render->wnd->w, render->wnd->h)) *\/ */
/* /\* 		return; *\/ */
/* /\* 	int x0 = s[0].x, x1 = s[1].x; *\/ */
/* /\* 	int y0 = s[0].y, y1 = s[1].y; *\/ */
/* /\* 	bool steep = fdf_abs(y1 - y0) > fdf_abs(x1 - x0); *\/ */

/* /\* 	// Swap the coordinates because the segment is backwards *\/ */
/* /\* 	if (steep) *\/ */
/* /\* 	{ *\/ */
/* /\* 		fdf_swap(&x0, &y0); *\/ */
/* /\* 		fdf_swap(&x1, &y1); *\/ */
/* /\* 	} *\/ */
/* /\* 	if (x0 > x1) *\/ */
/* /\* 	{ *\/ */
/* /\* 		fdf_swap(&x0, &x1); *\/ */
/* /\* 		fdf_swap(&y0, &y1); *\/ */
/* /\* 	} *\/ */

/* /\* 	float dx = x1 - x0; *\/ */
/* /\* 	float dy = y1 - y0; *\/ */
/* /\* 	float gradient; *\/ */
/* /\* 	if (dx != 0.0) *\/ */
/* /\* 		gradient = dy / dx; *\/ */
/* /\* 	else *\/ */
/* /\* 		gradient = 1; *\/ */

/* /\* 	float intersect_y = y0; *\/ */

/* /\* 	if (steep) *\/ */
/* /\* 	{ *\/ */
/* /\* 		int x = x0; *\/ */
/* /\* 		while (x <= x1) *\/ */
/* /\* 		{ *\/ */
/* /\* 			t_fdf_color color = shader((t_vec2){intersect_y, x}, x - x0, dx, data); *\/ */
/* /\* 			fdf_plot(render, (t_vec2){intersect_y, x}, color, fdf_dec_part(intersect_y)); *\/ */
/* /\* 			fdf_plot(render, (t_vec2){intersect_y - 1, x}, color, fdf_inv_dec_part(intersect_y)); *\/ */
/* /\* 			intersect_y += gradient; *\/ */
/* /\* 			x++; *\/ */
/* /\* 		} *\/ */
/* /\* 	} *\/ */
/* /\* 	else *\/ */
/* /\* 	{ *\/ */
/* /\* 		int x = x0; *\/ */
/* /\* 		while (x <= x1) *\/ */
/* /\* 		{ *\/ */
/* /\* 			t_fdf_color color = shader((t_vec2){x, intersect_y}, x - x0, dx, data); *\/ */
/* /\* 			fdf_plot(render, (t_vec2){x, intersect_y}, color, fdf_dec_part(intersect_y)); *\/ */
/* /\* 			fdf_plot(render, (t_vec2){x, intersect_y - 1}, color, fdf_inv_dec_part(intersect_y)); *\/ */
/* /\* 			intersect_y += gradient; *\/ */
/* /\* 			x++; *\/ */
/* /\* 		} *\/ */
/* /\* 	} *\/ */
/* /\* } *\/ */
