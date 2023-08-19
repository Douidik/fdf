#include "mat.h"
#include <math.h>

// Using a 90 degrees field of view for the perspective projection
// the ratio of the camera and the near clip plane is: 1 / tan (90 / 2)
#define FDF_FOV (0.6173696237835551)

// Perspective projection of a 3d point into the screen space coordinates
// [ ( h/w ) * ( 1 / (tan(fov)/2) ) * x                     ]
// |           ( 1 / (tan(fov)/2) ) * y                     |
// [ ( far / (far-near) ) * z - ( far / (far-near) ) * near ]

t_mat4f mat4_perspective(t_projection_plane p)
{
	t_mat4f mat;
	float f;

	f = FDF_FOV * (1 / p.zoom);
	mat = (t_mat4f){0};
	mat.m[0][0] = p.ratio * f;
	mat.m[1][1] = f;
	mat.m[2][2] = p.far / (p.far - p.near);
	mat.m[2][3] = (-p.far * p.near) / (p.far - p.near);
	mat.m[3][2] = 1.0f;
	return (mat);
}

t_mat4f mat4_orthographic(t_projection_plane p)
{
	t_mat4f mat;
	float w;
	float h;

	p.left *= p.zoom;
	p.right *= p.zoom;
	p.bottom *= p.zoom;
	p.top *= p.zoom;
	w = p.right - p.left;
	h = p.top - p.bottom;
	mat = (t_mat4f){0};
	mat.m[0][0] = 2 / w;
	mat.m[0][3] = -(p.right + p.left) / w;
	mat.m[1][1] = 2 / h;
	mat.m[1][3] = (p.top + p.bottom) / h;
	mat.m[2][2] = -2 / p.far;
	mat.m[2][3] = p.far;
	mat.m[3][3] = 1;
	return (mat);
}

/* #define FDF_SQRT2 (1.41421356237) */
/* #define FDF_SQRT6 (2.44948974278) */
/* #define FDF_SQRT_2_3 (0.816496580928) */

/* t_mat4f mat4_isometric(t_projection_plane p) */
/* { */
/* 	t_mat4f mat; */
	
/* 	(void)p; */
/* 	mat = (t_mat4f){0}; */
/* 	mat.m[0][0] = FDF_SQRT2 / 2; */
/* 	mat.m[0][1] = -FDF_SQRT2 / 2; */
/* 	mat.m[1][0] = -1 / FDF_SQRT6; */
/* 	mat.m[1][1] = -1 / FDF_SQRT6; */
/* 	mat.m[1][2] = FDF_SQRT_2_3; */
/* 	return (mat); */
/* } */
