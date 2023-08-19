#include "camera.h"
#include "fdf.h"
#include "map.h"
#include "map_shader.h"
#include "math/lerp.h"
#include "renderer.h"
#include "window.h"
#include <stddef.h>
#include <stdlib.h>

void fdf_make_vertex(t_fdf_renderer *render, t_fdf_map *map, t_mat4f *mvp, t_vec2 coords);
void fdf_draw_vertex(t_fdf_renderer *render, t_fdf_vertex *a, t_fdf_vertex *b);

void fdf_draw_map(t_fdf_renderer *render, t_fdf_camera *cam, t_fdf_map *map)
{
	int x;
	int y;
	int i;
	t_mat4f *mvp;
	t_fdf_vertex *v;

	mvp = fdf_camera_mvp(cam);
	y = 0;
	while (y < map->h)
	{
		x = 0;
		while (x < map->w)
			fdf_make_vertex(render, map, mvp, (t_vec2){x++, y});
		y++;
	}
	i = 0;
	while (i < map->w * map->h)
	{
		v = &render->vs[i++];
		if (v->coords.x + 1 < map->w)
			fdf_draw_vertex(render, v, &render->vs[v->coords.y * map->w + (v->coords.x + 1)]);
		if (v->coords.y + 1 < map->h)
			fdf_draw_vertex(render, v, &render->vs[(v->coords.y + 1) * map->w + v->coords.x]);
	}
}

t_fdf_color fdf_vertex_color(t_fdf_renderer *render, t_fdf_map *map, int i)
{
	t_fdf_palette *pal;
	int t;
	int u;

	pal = &render->fdf->pals[render->fdf->pal];
	if (!pal->enabled)
	{
		if (!map->colors[i].v)
			return (FDF_WHITE);
		return (map->colors[i]);
	}
	else
	{
		t = map->min + map->verts[i];
		u = map->min + map->max;
		return (fdf_lerp_rgbs((float)t / u, pal->colors, pal->len));
	}
}

void fdf_make_vertex(t_fdf_renderer *render, t_fdf_map *map, t_mat4f *mvp, t_vec2 coords)
{
	size_t i;
	t_fdf_vertex *v;
	t_vec4f p;

	i = coords.y * map->w + coords.x;
	v = &render->vs[i];
	v->color = fdf_vertex_color(render, map, i);
	v->coords = coords;
	p = (t_vec4f){coords.x, map->verts[i] * fdf_map_factor(map), coords.y, 1.0};
	p = mat4_mul_vec4(*mvp, p);
	v->hidden = p.w <= -p.z;
	v->pos.x = (1 - p.x / p.w) * 0.5 * render->wnd->w;
	v->pos.y = (1 - p.y / p.w) * 0.5 * render->wnd->h;
	v->z = p.z;
}

void fdf_draw_vertex(t_fdf_renderer *render, t_fdf_vertex *a, t_fdf_vertex *b)
{
	t_vec2 s[2];
	t_fdf_map_shader_data data;

	if (!a || !b || a->hidden || b->hidden)
		return;
	s[0] = a->pos;
	s[1] = b->pos;
	data.a = a;
	data.b = b;
	data.w = render->wnd->w;
	data.h = render->wnd->h;
	data.zbuffer = render->zbuffer;
	fdf_draw_segment(render, s, fdf_map_shader, &data);
}
