#include "mat.h"

t_mat4 mat4_translation(t_mat4 mat, t_vec3f v)
{
	t_mat4 tsl;

	tsl = mat4_identity();
	tsl.m[0][3] = v.x;
	tsl.m[1][3] = v.y;
	tsl.m[2][3] = v.z;
	return (mat4_mul_mat4(mat, tsl));
}

t_mat4 mat4_rotation(t_mat4 mat, t_vec3f v)
{
	mat = mat4_mul_mat4(mat, mat4_rotation_x(v.x));
	mat = mat4_mul_mat4(mat, mat4_rotation_y(v.y));
	return (mat);
}

t_mat4 mat4_scale(t_mat4 mat, t_vec3f v)
{
	t_mat4 scl;

	scl = mat4_identity();
	scl.m[0][0] = v.x;
	scl.m[1][1] = v.y;
	scl.m[2][2] = v.z;
	return (mat4_mul_mat4(scl, mat));
}
