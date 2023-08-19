#include "math/cohen_sutherland.h"
#include "renderer.h"
#include "util/cmp.h"
#include "window.h"
#include <math.h>

typedef struct s_fdf_segment
{
	int steep;
	int x;
	int start_x;
	int end_x;
	float y;
	float step;
	t_vec2f d;
	t_fdf_shader shader;
	void *data;
} t_fdf_segment;

void fdf_swap(int *v, int *w)
{
	int tmp;

	tmp = *v;
	*v = *w;
	*w = tmp;
}

float fdf_dec_part(float f)
{
	if (f > 0)
		return (f - ((int)f));
	else
		return (f - ((int)f + 1));
}

/* void fdf_segment_point(t_fdf_renderer *render, t_fdf_segment *s, t_vec2 pos, t_fdf_color color) */
/* { */

/* } */

void fdf_segment_trace(t_fdf_renderer *render, t_fdf_segment *s)
{
	t_fdf_color color;

	if (s->steep)
	{
		while (s->x <= s->end_x)
		{
			color = s->shader((t_vec2){s->y, s->x}, s->x - s->start_x, s->d.x, s->data);
			if (color.a != 0)
			{
				color.a = (uint8_t)(fdf_dec_part(s->y) * 255);
				fdf_draw_pixel(render, (t_vec2){s->y, s->x}, color);
				color.a = (uint8_t)((1 - fdf_dec_part(s->y)) * 255);
				fdf_draw_pixel(render, (t_vec2){s->y - 1, s->x}, color);
			}
			s->y += s->step;
			s->x++;
		}
	}
	else
	{
		while (s->x <= s->end_x && 0)
		{
			color = s->shader((t_vec2){s->x, s->y}, s->x - s->start_x, s->d.x, s->data);
			if (color.a != 0)
			{
				color.a = (uint8_t)(fdf_dec_part(s->y) * 255);
				fdf_draw_pixel(render, (t_vec2){s->x, s->y}, color);
				color.a = (uint8_t)((1 - fdf_dec_part(s->y)) * 255);
				fdf_draw_pixel(render, (t_vec2){s->x, s->y - 1}, color);
			}
			s->y += s->step;
			s->x++;
		}
	}
}

void fdf_draw_segment_quality(t_fdf_renderer *render, t_vec2 p[2], t_fdf_shader shader, void *data)
{
	t_fdf_segment s;

	if (!cohen_sutherland((t_vec2 *[2]){&p[0], &p[1]}, render->wnd->w, render->wnd->h))
		return;
	s.steep = fdf_abs(p[1].y - p[0].y) > fdf_abs(p[1].x - p[0].x);
	if (s.steep)
	{
		fdf_swap(&p[0].x, &p[0].y);
		fdf_swap(&p[1].x, &p[1].y);
	}
	if (p[0].x > p[1].x)
	{
		fdf_swap(&p[0].x, &p[1].x);
		fdf_swap(&p[0].y, &p[1].y);
	}
	s.d = (t_vec2f){p[1].x - p[0].x, p[1].y - p[0].y};
	s.step = 1;
	if (s.d.x != 0.0)
		s.step = s.d.y / s.d.x;
	s.x = p[0].x;
	s.y = p[0].y;
	s.start_x = p[0].x;
	s.end_x = p[1].x;
	s.shader = shader;
	s.data = data;
	fdf_segment_trace(render, &s);
}
