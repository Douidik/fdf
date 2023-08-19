/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuppan <jsuppan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 20:35:40 by jsuppan           #+#    #+#             */
/*   Updated: 2023/08/19 20:36:45 by jsuppan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

struct	s_fdf_map;

typedef struct s_fdf_parser
{
	char	*src;
	int		fd;
}	t_fdf_parser;

t_fdf_parser		*fdf_parser_new(int fd);
t_fdf_parser		*fdf_parser_free(t_fdf_parser *parser);
struct s_fdf_map	*fdf_parse_map(t_fdf_parser *parser, struct s_fdf_map *map);

#endif
