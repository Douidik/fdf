#ifndef FDF_MAT_H
#define FDF_MAT_H

#include "vec.h"

typedef struct s_mat4f
{
	float m[4][4];
} t_mat4f;

// Projection plane description
// The zoom component is a factor for the field of view in the perspective projection
// and a factor of size of the bounding boxes in the orthographic projection
typedef struct s_projection_plane
{
	float zoom;
	float ratio;
	float near;
	float far;
	float top;
	float bottom;
	float left;
	float right;
} t_projection_plane;

t_mat4f mat4_identity(void);

t_mat4f mat4_perspective(t_projection_plane p);
t_mat4f mat4_orthographic(t_projection_plane p);
t_mat4f mat4_isometric(t_projection_plane p);

t_mat4f mat4_rotation_x(float x);
t_mat4f mat4_rotation_y(float y);

t_mat4f mat4_watch(t_mat4f mat, t_vec3f pos, t_vec3f center, t_vec3f up);
t_mat4f mat4_translate(t_mat4f mat, t_vec3f v);
t_mat4f mat4_rotate(t_mat4f mat, t_vec3f v);
t_mat4f mat4_scale(t_mat4f mat, t_vec3f v);

t_mat4f mat4_mul_mat4(t_mat4f a, t_mat4f b);
t_mat4f mat4_mul_scalar(t_mat4f mat, float s);
t_vec4f mat4_mul_vec4(t_mat4f mat, t_vec4f vec);

#endif
