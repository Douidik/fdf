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
