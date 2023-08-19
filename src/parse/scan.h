/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuppan <jsuppan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 20:34:20 by jsuppan           #+#    #+#             */
/*   Updated: 2023/08/19 21:20:00 by jsuppan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAN_H
# define SCAN_H

# include <stddef.h>

typedef enum e_fdf_token_kind
{
	FDF_SPACE = 1 << 0,
	FDF_NEWL = 1 << 1,
	FDF_COMMA = 1 << 2,
	FDF_COLOR = 1 << 3,
	FDF_VERTEX = 1 << 4,
	FDF_EOF = 1 << 5,
}	t_fdf_token_kind;

typedef struct s_fdf_token
{
	const char			*expr;
	size_t				len;
	t_fdf_token_kind	kind;
}	t_fdf_token;

t_fdf_token	*fdf_scan(const char *src, t_fdf_token *tok);
int			fdf_atoi(t_fdf_token tok);

#endif
