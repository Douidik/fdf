#ifndef FDF_VEC_H
#define FDF_VEC_H

typedef struct s_vec2
{
	int x;
	int y;
} t_vec2;

typedef struct s_vec2f
{
	float x;
	float y;
} t_vec2f;

typedef struct s_vec3f
{
	float x;
	float y;
	float z;
} t_vec3f;

typedef struct s_vec4f
{
	float x;
	float y;
	float z;
	float w;
} t_vec4f;

t_vec2f vec2_to_vec2f(t_vec2 v);
t_vec3f vec3f_norm(t_vec3f v);
t_vec3f vec3f_cross(t_vec3f v, t_vec3f w);
float vec3f_dot(t_vec3f v, t_vec3f w);

#endif
