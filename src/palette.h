/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuppan <jsuppan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 20:12:06 by jsuppan           #+#    #+#             */
/*   Updated: 2023/08/21 20:01:12 by jsuppan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PALETTE_H
# define PALETTE_H

# include "render/color.h"
# include <stddef.h>

struct	s_fdf;

typedef struct s_fdf_palette
{
	int			enabled;
	const char	*name;
	size_t		len;
	t_fdf_color	colors[8];
}	t_fdf_palette;

void	fdf_pals_init(struct s_fdf *fdf);
int		fdf_pals_on_keypress(int k, struct s_fdf *fdf);

#endif
