#include "vec.h"
#include <math.h>

t_vec2f vec2_to_vec2f(t_vec2 v)
{
	return (t_vec2f){v.x, v.y};
}

t_vec3f vec3f_norm(t_vec3f v)
{
	float mag2;
	float mag;
	t_vec3f norm;

	mag2 = v.x * v.x + v.y * v.y + v.z * v.z;
	if (mag2 != 0)
	{
		mag = sqrt(mag2);
		norm.x = v.x / mag;
		norm.y = v.y / mag;
		norm.z = v.z / mag;
		return (norm);
	}
	return ((t_vec3f){0});
}

t_vec3f vec3f_cross(t_vec3f v, t_vec3f w)
{
	t_vec3f cross;

	cross.x = v.y * w.z - v.z * w.y;
	cross.y = v.z * w.x - v.x * w.z;
	cross.z = v.x * w.y - v.y * w.x;
	return (cross);
}

float vec3f_dot(t_vec3f v, t_vec3f w)
{
	return (v.x * w.x + v.y * w.y + v.z * w.z);
}
