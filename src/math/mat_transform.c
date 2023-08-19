#include "mat.h"

t_mat4f mat4_translate(t_mat4f mat, t_vec3f v)
{
	t_mat4f transform;

	transform = mat4_identity();
	transform.m[0][3] += v.x;
	transform.m[1][3] += v.y;
	transform.m[2][3] += v.z;
	return (mat4_mul_mat4(mat, transform));
}

t_mat4f mat4_rotate(t_mat4f mat, t_vec3f v)
{
	mat = mat4_mul_mat4(mat, mat4_rotation_x(v.x));
	mat = mat4_mul_mat4(mat, mat4_rotation_y(v.y));
	return (mat);
}

t_mat4f mat4_scale(t_mat4f mat, t_vec3f v)
{
	t_mat4f transform;

	transform = mat4_identity();
	transform.m[0][0] *= v.x;
	transform.m[1][1] *= v.y;
	transform.m[2][2] *= v.z;
	return (mat4_mul_mat4(transform, mat));
}
