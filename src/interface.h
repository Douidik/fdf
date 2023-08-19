/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuppan <jsuppan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 20:06:11 by jsuppan           #+#    #+#             */
/*   Updated: 2023/08/19 20:07:15 by jsuppan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERFACE_H
# define INTERFACE_H

# include "math/vec.h"
# include "render/color.h"

struct	s_fdf;
struct	s_fdf_window;

typedef struct s_fdf_interface
{
	struct s_fdf	*fdf;
	t_vec2			pos;
	t_vec2			step;
}	t_fdf_interface;

t_fdf_interface	*fdf_interface_new(struct s_fdf *fdf);
t_fdf_interface	*fdf_interface_free(t_fdf_interface *interface);
void			fdf_interface_draw(t_fdf_interface *interface, const char *s);
void			fdf_interface_update(t_fdf_interface *interface,
					struct s_fdf *fdf);

#endif
