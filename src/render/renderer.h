#ifndef FDF_RENDERER_H
#define FDF_RENDERER_H

#include "color.h"
#include "math/vec.h"
#include <stdint.h>

struct s_fdf_map;
struct s_fdf_nav;
struct s_fdf_window;
struct s_fdf_camera;
struct s_fdf;

typedef enum e_fdf_endian
{
	FDF_ENDIAN_SMALL = 0,
	FDF_ENDIAN_BIG = 1,
} t_fdf_endian;

typedef enum e_fdf_render_mode
{
	FDF_RENDER_FAST = 0,
	FDF_RENDER_QUALITY = 1,
	FDF_RENDER_MODE_COUNT = 2
} t_fdf_render_mode;

typedef struct s_fdf_vertex
{
	int hidden;
	float z;
	t_vec2 coords;
	t_vec2 pos;
	t_fdf_color color;
} t_fdf_vertex;

typedef struct s_fdf_renderer
{
	void *mlx;
	struct s_fdf *fdf;
	struct s_fdf_window *wnd;
	t_fdf_vertex *vs;
	float *zbuffer;
	void *image;
	uint8_t *stream;
	int bpp;
	int sw;
	t_fdf_endian endian;
	t_fdf_render_mode render_mode;
} t_fdf_renderer;

typedef t_fdf_color (*t_fdf_shader)(t_vec2, int, int, void *);

t_fdf_renderer *fdf_renderer_new(void *mlx, struct s_fdf *fdf);
t_fdf_renderer *fdf_renderer_free(t_fdf_renderer *render);
void fdf_render_clear(t_fdf_renderer *render, t_fdf_color background_color);
void fdf_render_present(t_fdf_renderer *render);
int fdf_render_on_keypress(int k, struct s_fdf *fdf);

void fdf_draw_pixel(t_fdf_renderer *render, t_vec2 pos, t_fdf_color color);
void fdf_draw_segment(t_fdf_renderer *render, t_vec2 p[2], t_fdf_shader shader, void *data);
void fdf_draw_segment_fast(t_fdf_renderer *render, t_vec2 p[2], t_fdf_shader shader, void *data);
void fdf_draw_segment_quality(t_fdf_renderer *render, t_vec2 p[2], t_fdf_shader shader, void *data);
void fdf_draw_rect(t_fdf_renderer *render, t_vec2 s[2], t_fdf_color color);

void fdf_draw_map(t_fdf_renderer *render, struct s_fdf_camera *cam, struct s_fdf_map *map);
void fdf_draw_nav(t_fdf_renderer *render, struct s_fdf_nav *nav);

#endif
