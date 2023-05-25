#include "parser.h"
#include "map.h"
#include "math/vec.h"
#include "scan.h"
#include "util/cmp.h"
#include "util/read_fd.h"
#include <fcntl.h>
#include <libft.h>
#include <stdlib.h>

t_fdf_parser *fdf_parser_new(int fd)
{
	t_fdf_parser *parser;

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

t_fdf_parser *fdf_parser_free(t_fdf_parser *parser)
{
	if (parser != NULL)
	{
		if (parser->src != NULL)
			free(parser->src);
		free(parser);
	}
	return (NULL);
}

void fdf_parse_size(t_fdf_parser *parser, t_fdf_map *map)
{
	t_fdf_token tok;

	map->w = 0;
	map->h = 0;
	tok = (t_fdf_token){0};
	while (fdf_scan(parser->src, &tok)->kind & ~(FDF_EOF | FDF_NEWL))
	{
		if (tok.kind & FDF_INT)
			map->w++;
	}
	tok = (t_fdf_token){0};
	while (fdf_scan(parser->src, &tok)->kind & ~(FDF_EOF))
	{
		while (fdf_scan(parser->src, &tok)->kind & (FDF_INT | FDF_SPACE))
			;
		map->h++;
	}
}

t_fdf_map *fdf_parse_map(t_fdf_parser *parser, t_fdf_map *map)
{
	t_fdf_token tok;
	t_vec2 pos;

	fdf_parse_size(parser, map);
	map->data = ft_calloc(map->w * map->h, sizeof(int));
	if (!map->data)
		return (NULL);
	tok = (t_fdf_token){0};
	pos = (t_vec2){0};
	while (fdf_scan(parser->src, &tok)->kind & ~FDF_EOF)
	{
		if (tok.kind & FDF_NEWL)
		{
			pos.x = 0;
			pos.y++;
		}
		else if (tok.kind & FDF_INT)
		{
			map->data[pos.y * map->w + pos.x] = fdf_atoi(tok);
			pos.x++;
		}
	}
	map->min = fdf_array_min(map->data, map->w * map->h);
	map->max = fdf_array_max(map->data, map->w * map->h);
	map->amplitude = fdf_abs(map->max - map->min) + 1;
	return (map);
}
