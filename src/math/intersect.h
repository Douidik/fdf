/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuppan <jsuppan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 21:25:55 by jsuppan           #+#    #+#             */
/*   Updated: 2023/08/19 21:26:11 by jsuppan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECT_H
# define INTERSECT_H

# include "vec.h"

int	intersect_segment_x(t_vec2 *s[2], int y);
int	intersect_segment_y(t_vec2 *s[2], int x);

#endif