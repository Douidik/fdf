/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuppan <jsuppan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 21:19:49 by jsuppan           #+#    #+#             */
/*   Updated: 2023/08/19 21:19:56 by jsuppan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

t_fdf_color	fdf_color_hex(uint32_t v)
{
	return ((t_fdf_color){.v = v});
}
