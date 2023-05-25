#ifndef FDF_CAMERA_H
#define FDF_CAMERA_H

#include "math/mat.h"

struct s_fdf_window;
struct s_fdf_nav;
struct s_fdf_map;
struct s_fdf;

typedef struct s_fdf_camera
{
	t_perspective_plane persp;
	int obsolete;
	t_vec3f pos;
	t_vec3f rot;
	t_vec3f scale;
	t_mat4 m;
	t_mat4 v;
	t_mat4 p;
	t_mat4 mvp;
} t_fdf_camera;

t_fdf_camera fdf_camera_new(float fov, struct s_fdf_window *wnd);
t_mat4 *fdf_camera_mvp(t_fdf_camera *cam);
void fdf_camera_nav(t_fdf_camera *cam, struct s_fdf_window *wnd, struct s_fdf_nav *nav);

#endif
