#include "mat.h"
#include <math.h>

t_mat4f mat4_rotation_x(float x)
{
    t_mat4f mat;
    float sin;
    float cos;

    mat = mat4_identity();
    sin = sinf(x);
    cos = cosf(x);
    mat.m[1][1] = +cos;
    mat.m[1][2] = -sin;
    mat.m[2][1] = +sin;
    mat.m[2][2] = +cos;
    return (mat);
}

t_mat4f mat4_rotation_y(float y)
{
    t_mat4f mat;
    float sin;
    float cos;

    mat = mat4_identity();
    sin = sinf(y);
    cos = cosf(y);
    mat.m[0][0] = +cos;
    mat.m[0][2] = +sin;
    mat.m[2][0] = -sin;
    mat.m[2][2] = +cos;
    return (mat);
}
