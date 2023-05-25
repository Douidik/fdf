#include "math/cohen_sutherland.h"
#include "renderer.h"
#include "window.h"
#include <math.h>

void fdf_draw_segment(t_fdf_renderer *render, t_vec2 s[2], t_fdf_shader shader, void *data)
{
	t_vec2f d;
	t_vec2f v;
	int len;
	int i;
	t_fdf_color color;

	if (!cohen_sutherland((t_vec2 *[2]){&s[0], &s[1]}, render->wnd->w, render->wnd->h))
		return;
	d.x = s[1].x - s[0].x;
	d.y = s[1].y - s[0].y;
	v = (t_vec2f){s[0].x, s[0].y};
	len = fmaxf(fabsf(d.x), fabsf(d.y));
	if (len != 0)
	{
		d.x /= len;
		d.y /= len;
	}
	i = 0;
	while (i < len)
	{
		color = shader((t_vec2){v.x, v.y}, i, len, data);
		fdf_draw_pixel(render, (t_vec2){v.x, v.y}, color);
		v.x += d.x;
		v.y += d.y;
		i++;
	}
}
