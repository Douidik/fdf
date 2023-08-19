/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lerp.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuppan <jsuppan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 21:24:57 by jsuppan           #+#    #+#             */
/*   Updated: 2023/08/19 21:25:26 by jsuppan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LERP_H
# define LERP_H

# include "render/color.h"
# include <stddef.h>

int			fdf_lerp(float t, int a, int b);
t_fdf_color	fdf_lerp_rgb(float t, t_fdf_color a, t_fdf_color b);
t_fdf_color	fdf_lerp_rgbs(float t, t_fdf_color p[], size_t len);

#endif
