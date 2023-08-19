#ifndef FDF_CAMERA_H
#define FDF_CAMERA_H

#include "math/mat.h"

struct s_fdf_window;
struct s_fdf_nav;
struct s_fdf_map;
struct s_fdf;

typedef enum e_fdf_camera_projection
{
	FDF_CAM_PERSPECTIVE,
	FDF_CAM_ORTHOGRAPHIC,
	FDF_CAM_ISOMETRIC,
} t_fdf_camera_projection;

typedef struct s_fdf_camera
{
	struct s_fdf_window *wnd;
	struct s_fdf_map *map;
	t_fdf_camera_projection proj;
	t_projection_plane plane;
	int obsolete;
	float pan_speed;
	float polar;
	float azimuth;
	float radius;
	t_vec3f pos;
	t_vec3f rot;
	t_vec3f pan;
	t_vec3f center;
	t_mat4f m;
	t_mat4f v;
	t_mat4f p;
	t_mat4f mvp;
} t_fdf_camera;

t_fdf_camera fdf_camera_new(struct s_fdf_map *map, struct s_fdf_window *wnd);
t_mat4f *fdf_camera_mvp(t_fdf_camera *cam);
void fdf_camera_orbit(t_fdf_camera *cam, float polar, float azimuth);
void fdf_camera_nav(t_fdf_camera *cam, struct s_fdf_window *wnd, struct s_fdf_nav *nav);
int fdf_camera_on_keypress(int k, struct s_fdf *fdf);
const char *fdf_camera_projection_name(t_fdf_camera_projection proj);

#endif
