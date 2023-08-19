/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuppan <jsuppan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 20:36:48 by jsuppan           #+#    #+#             */
/*   Updated: 2023/08/19 20:38:11 by jsuppan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "map.h"
#include "math/vec.h"
#include "scan.h"
#include "util/cmp.h"
#include "util/mem.h"
#include "util/read_fd.h"
#include <fcntl.h>
#include <libft.h>
#include <stdlib.h>

t_fdf_parser	*fdf_parser_new(int fd)
{
	t_fdf_parser	*parser;

	parser = ft_calloc(1, sizeof(t_fdf_parser));
	if (!parser)
		return (NULL);
	parser->fd = fd;
	if (parser->fd < 0)
		return (fdf_parser_free(parser));
	parser->src = fdf_read_fd(parser->fd);
	if (!parser->src)
		return (fdf_parser_free(parser));
	return (parser);
}

t_fdf_parser	*fdf_parser_free(t_fdf_parser *parser)
{
	if (parser != NULL)
	{
		if (parser->src != NULL)
			free(parser->src);
		free(parser);
	}
	return (NULL);
}

t_fdf_map	*fdf_parse_init(t_fdf_parser *parser, t_fdf_map *map)
{
	t_fdf_token	tok;
	int			w;
	int			h;

	w = 0;
	h = 0;
	tok = (t_fdf_token){0};
	while (fdf_scan(parser->src, &tok)->kind & ~(FDF_EOF | FDF_NEWL))
	{
		if (tok.kind & FDF_VERTEX)
			w++;
	}
	tok = (t_fdf_token){0};
	while (fdf_scan(parser->src, &tok)->kind & ~(FDF_EOF))
	{
		while (fdf_scan(parser->src, &tok)->kind
			& (FDF_VERTEX | FDF_SPACE | FDF_COLOR))
			;
		h++;
	}
	return (fdf_map_init(map, w, h));
}

t_fdf_map	*fdf_parse_map(t_fdf_parser *parser, t_fdf_map *map)
{
	t_fdf_token	tok;
	t_vec2		pos;
	t_fdf_color	*color;

	if (!fdf_parse_init(parser, map))
		return (NULL);
	tok = (t_fdf_token){0};
	pos = (t_vec2){0};
	while (fdf_scan(parser->src, &tok)->kind & ~FDF_EOF)
	{
		if (tok.kind & FDF_NEWL)
			pos = (t_vec2){0, pos.y + 1};
		else if (tok.kind & FDF_VERTEX)
		{
			if (pos.x >= map->w || pos.y >= map->h)
				return (fdf_map_free(map));
			color = &map->colors[pos.y * map->w + pos.x];
			map->verts[pos.y * map->w + pos.x++] = fdf_atoi(tok);
		}
		else if (tok.kind & FDF_COLOR)
			color->v = fdf_atoi(tok);
	}
	map->min = fdf_array_min(map->verts, map->w * map->h);
	map->max = fdf_array_max(map->verts, map->w * map->h);
	return (map);
}
