#include "camera.h"
#include "fdf.h"
#include "map.h"
#include "window.h"
#include <X11/keysym.h>
#include <math.h>

// The 'isometric projection' is just an orthographic projection but with a certain angle
// Y: -45, X: -30, these angles are converted in radians
#define FDF_ISO_AZIMUTH (-2.268928)
#define FDF_ISO_POLAR (-0.5235988)

t_fdf_camera fdf_camera_new(t_fdf_map *map, t_fdf_window *wnd)
{
	t_fdf_camera cam;

	cam = (t_fdf_camera){0};
	cam.wnd = wnd;
	cam.map = map;
	cam.plane.zoom = 1;
	cam.plane.ratio = ((float)wnd->w) / ((float)wnd->h);
	cam.plane.near = 0.1;
	cam.plane.far = 100.0;
	cam.plane.top = 1;
	cam.plane.bottom = -64;
	cam.plane.right = +64;
	cam.plane.left = -64;
	fdf_camera_orbit(&cam, 0, M_PI_2);
	cam.radius = fmaxf((float)map->w, (float)map->h);
	cam.center.x = -(float)map->w / 2;
	cam.center.z = -(float)map->h / 2;
	cam.proj = FDF_CAM_ISOMETRIC;
	fdf_camera_orbit(&cam, FDF_ISO_POLAR, FDF_ISO_AZIMUTH);
	cam.obsolete = 1;
	return (cam);
}

t_mat4f *fdf_camera_mvp(t_fdf_camera *cam)
{
	t_vec3f pos;

	pos.x = cam->center.x + cam->radius * cosf(cam->polar) * cosf(cam->azimuth);
	pos.y = cam->center.y + cam->radius * sinf(cam->polar);
	pos.z = cam->center.z + cam->radius * cosf(cam->polar) * sinf(cam->azimuth);
	if (cam->obsolete)
	{
		cam->mvp = mat4_identity();
		cam->m = mat4_identity();
		cam->v = mat4_identity();
		if (cam->proj == FDF_CAM_PERSPECTIVE)
			cam->p = mat4_perspective(cam->plane);
		if (cam->proj == FDF_CAM_ORTHOGRAPHIC || cam->proj == FDF_CAM_ISOMETRIC)
			cam->p = mat4_orthographic(cam->plane);
		cam->v = mat4_rotate(cam->v, cam->rot);
		cam->v = mat4_translate(cam->v, pos);
		cam->v = mat4_translate(cam->v, cam->pan);
		cam->mvp = mat4_mul_mat4(cam->mvp, cam->p);
		cam->mvp = mat4_mul_mat4(cam->mvp, cam->v);
		cam->mvp = mat4_mul_mat4(cam->mvp, cam->m);
	}
	cam->obsolete = 0;
	return (&cam->mvp);
}

void fdf_camera_orbit(t_fdf_camera *cam, float polar, float azimuth)
{
	if (cam->azimuth != azimuth || cam->polar != polar)
	{
		cam->polar = polar;
		cam->azimuth = azimuth;
		cam->rot.x = cam->polar;
		cam->rot.y = -M_PI_2 + cam->azimuth;
		cam->obsolete = 1;
	}
}

int fdf_camera_on_keypress(int k, t_fdf *fdf)
{
	t_fdf_camera *cam;

	cam = &fdf->cam;
	if (k >= XK_7 || k <= XK_9)
	{
		cam->obsolete = 1;
		if (k == XK_7)
			cam->proj = FDF_CAM_PERSPECTIVE;
		if (k == XK_8)
			cam->proj = FDF_CAM_ORTHOGRAPHIC;
		if (k == XK_9)
		{
			cam->proj = FDF_CAM_ISOMETRIC;
			fdf_camera_orbit(cam, FDF_ISO_POLAR, FDF_ISO_AZIMUTH);
		}
		return (1);
	}
	return (0);
}

const char *fdf_camera_projection_name(t_fdf_camera_projection proj)
{
	if (proj == FDF_CAM_PERSPECTIVE)
		return "perspective";
	else if (proj == FDF_CAM_ORTHOGRAPHIC)
		return "orthographic";
	else if (proj == FDF_CAM_ISOMETRIC)
		return "isometric";
	else
		return "?";
}
