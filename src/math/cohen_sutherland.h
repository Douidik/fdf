/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cohen_sutherland.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuppan <jsuppan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 21:26:46 by jsuppan           #+#    #+#             */
/*   Updated: 2023/08/19 21:26:58 by jsuppan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COHEN_SUTHERLAND_H
# define COHEN_SUTHERLAND_H

# include "vec.h"

int	cohen_sutherland(t_vec2 *s[2], int w, int h);

#endif