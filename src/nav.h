/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nav.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuppan <jsuppan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 20:09:12 by jsuppan           #+#    #+#             */
/*   Updated: 2023/08/19 20:09:42 by jsuppan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NAV_H
# define NAV_H

# include "camera.h"
# include "math/vec.h"

struct	s_fdf;

typedef enum e_fdf_nav_input_type
{
	FDF_NAV_NONE,
	FDF_NAV_ORBIT,
	FDF_NAV_PAN,
	FDF_NAV_ZOOM,
	FDF_NAV_FLY,
}	t_fdf_nav_input_type;

typedef struct s_fdf_nav
{
	t_fdf_nav_input_type	type;
	t_fdf_camera			prev;
	t_vec2					anchor;
	int						k;
}	t_fdf_nav;

t_fdf_nav	fdf_nav_none(void);
int			fdf_nav_on_keypress(int k, struct s_fdf *fdf);
int			fdf_nav_on_keyrelease(int k, struct s_fdf *fdf);

#endif
