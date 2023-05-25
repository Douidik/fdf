#include "camera.h"
#include "map.h"
#include "window.h"
#include <math.h>

t_fdf_camera fdf_camera_new(float fov, t_fdf_window *wnd)
{
	t_fdf_camera cam;

	cam = (t_fdf_camera){0};
	cam.scale = (t_vec3f){1, 1, 1};
	cam.persp.fov = fov * M_PI / 180;
	cam.persp.ratio = ((float)wnd->w) / ((float)wnd->h);
	cam.persp.znear = 0.1;
	cam.persp.zfar = 100.0;
	cam.m = mat4_identity();
	cam.v = mat4_identity();
	cam.p = mat4_perspective(cam.persp);
	cam.obsolete = 1;
	return (cam);
}

t_mat4 *fdf_camera_mvp(t_fdf_camera *cam)
{
	if (cam->obsolete)
	{
		cam->mvp = mat4_identity();
		cam->m = mat4_identity();
		cam->v = mat4_identity();
		cam->p = mat4_perspective(cam->persp);
		cam->v = mat4_translation(cam->v, cam->pos);
		cam->m = mat4_rotation(cam->m, cam->rot);
		cam->m = mat4_scale(cam->m, cam->scale);
		cam->mvp = mat4_mul_mat4(cam->mvp, cam->p);
		cam->mvp = mat4_mul_mat4(cam->mvp, cam->v);
		cam->mvp = mat4_mul_mat4(cam->mvp, cam->m);
	}
	cam->obsolete = 0;
	return (&cam->mvp);
}
