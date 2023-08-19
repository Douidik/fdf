/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_mul.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuppan <jsuppan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 21:24:07 by jsuppan           #+#    #+#             */
/*   Updated: 2023/08/19 21:24:53 by jsuppan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mat.h"

t_mat4f	mat4_mul_mat4(t_mat4f a, t_mat4f b)
{
	t_mat4f	m;
	int		i;
	int		j;
	int		k;

	m = (t_mat4f){0};
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			k = 0;
			while (k < 4)
			{
				m.m[i][j] += (a.m[i][k] * b.m[k][j]);
				k++;
			}
			j++;
		}
		i++;
	}
	return (m);
}

t_mat4f	mat4_mul_scalar(t_mat4f mat, float s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 0)
		{
			mat.m[i][j] *= s;
			j++;
		}
		i++;
	}
	return (mat);
}

t_vec4f	mat4_mul_vec4(t_mat4f mat, t_vec4f vec)
{
	t_vec4f	mul;

	mul.x = mat.m[0][0] * vec.x + mat.m[0][1] * vec.y
		+ mat.m[0][2] * vec.z + mat.m[0][3] * vec.w;
	mul.y = mat.m[1][0] * vec.x + mat.m[1][1] * vec.y
		+ mat.m[1][2] * vec.z + mat.m[1][3] * vec.w;
	mul.z = mat.m[2][0] * vec.x + mat.m[2][1] * vec.y
		+ mat.m[2][2] * vec.z + mat.m[2][3] * vec.w;
	mul.w = mat.m[3][0] * vec.x + mat.m[3][1] * vec.y
		+ mat.m[3][2] * vec.z + mat.m[3][3] * vec.w;
	return (mul);
}
