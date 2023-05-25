#include "renderer.h"

/* void fdf_draw_pixel(t_fdf_renderer *render, t_vec2 pos, t_fdf_color color) */
/* { */
/* 	if (color.a != 255) */
/* 		fdf_draw_pixel_rgb(render, pos, color); */
/* 	else */
/* 		fdf_draw_pixel_rgb(render, pos, color); */
/* } */

/* void fdf_draw_pixel_rgb(t_fdf_renderer *render, t_vec2 pos, t_fdf_color rgb) */
/* { */
/* 	*(uint32_t *)(render->stream + pos.y * render->sw + pos.x * (render->bpp / 8)) |= (rgb.v & 0xffffff); */
/* } */

/* // NOTE! alpha channel is max(rgba, dst), this may be incorrect */
/* void fdf_draw_pixel_rgba(t_fdf_renderer *render, t_vec2 pos, t_fdf_color rgba) */
/* { */
/* 	t_fdf_color *dst; */
/* 	float alpha; */

/* 	if (rgba.a == 0) */
/* 		return; */
/* 	alpha = (float)rgba.a / 255; */
/* 	dst = (t_fdf_color *)(render->stream + pos.y * render->sw + pos.x * (render->bpp / 8)); */
/* 	dst->r = ((1.0 - alpha) * dst->r) + (alpha * rgba.r); */
/* 	dst->g = ((1.0 - alpha) * dst->g) + (alpha * rgba.g); */
/* 	dst->b = ((1.0 - alpha) * dst->b) + (alpha * rgba.b); */
/* } */

void fdf_draw_pixel(t_fdf_renderer *render, t_vec2 pos, t_fdf_color src)
{
	t_fdf_color *dst;
	float alpha;

	dst = (t_fdf_color *)(render->stream + pos.y * render->sw + pos.x * (render->bpp / 8));
	if (src.a == 0)
		return;
	if (src.a != 255)
	{
		alpha = (float)src.a / 255;
		dst->r = ((1.0 - alpha) * dst->r) + (alpha * src.r);
		dst->g = ((1.0 - alpha) * dst->g) + (alpha * src.g);
		dst->b = ((1.0 - alpha) * dst->b) + (alpha * src.b);
	}
	else
	{
		dst->v = src.v;
		dst->a = 255;
	}
}
