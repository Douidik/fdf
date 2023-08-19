/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuppan <jsuppan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 20:12:58 by jsuppan           #+#    #+#             */
/*   Updated: 2023/08/19 20:34:13 by jsuppan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include "math/vec.h"

typedef struct s_fdf_window
{
	void	*mlx;
	void	*impl;
	char	*name;
	int		w;
	int		h;
}	t_fdf_window;

t_fdf_window	*fdf_window_new(void *mlx, int w, int h, const char *filename);
t_fdf_window	*fdf_window_free(t_fdf_window *wnd);
t_vec2			fdf_window_mouse_get(t_fdf_window *wnd);
t_vec2			fdf_window_mouse_set(t_fdf_window *wnd, t_vec2 pos);

#endif