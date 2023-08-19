#include "mat.h"

t_mat4f mat4_identity(void)
{
    t_mat4f mat;

    mat = (t_mat4f){0};
    mat.m[0][0] = 1;
    mat.m[1][1] = 1;
    mat.m[2][2] = 1;
    mat.m[3][3] = 1;
    return (mat);
}
