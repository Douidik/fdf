/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuppan <jsuppan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 21:19:42 by jsuppan           #+#    #+#             */
/*   Updated: 2023/08/19 21:19:46 by jsuppan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_COLOR_H
#define FDF_COLOR_H

#include <stdint.h>

typedef union u_fdf_color
{
	struct
	{
		uint8_t r;
		uint8_t g;
		uint8_t b;
		uint8_t a;
	};
	uint32_t v;
} t_fdf_color;

t_fdf_color fdf_color_hex(uint32_t v);

#define FDF_WHITE       \
	(t_fdf_color)       \
	{                   \
		.v = 0xffffffff \
	}

#define FDF_RED         \
	(t_fdf_color)       \
	{                   \
		.v = 0xffff0000 \
	}

#define FDF_GREEN       \
	(t_fdf_color)       \
	{                   \
		.v = 0xff00ff00 \
	}

#define FDF_BLUE        \
	(t_fdf_color)       \
	{                   \
		.v = 0xff0000ff \
	}

#define FDF_PAL_BACKGROUND \
	(t_fdf_color)          \
	{                      \
		.v = 0x000e0e0e    \
	}

#define FDF_PAL_TEXT    \
	(t_fdf_color)       \
	{                   \
		.v = 0xffE1E8F5 \
	}

#define FDF_PAL_INTERFACE \
	(t_fdf_color)         \
	{                     \
		.v = 0x64191919   \
	}

#endif
