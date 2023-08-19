#include "renderer.h"

void fdf_draw_rect(t_fdf_renderer *render, t_vec2 s[2], t_fdf_color color)
{
	while (s[0].y < s[1].y)
	{
		s[0].x = 0;
		while (s[0].x < s[1].x)
		{
			fdf_draw_pixel(render, s[0], color);
			s[0].x++;
		}
		s[0].y++;
	}
}
