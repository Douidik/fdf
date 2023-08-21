/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuppan <jsuppan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 20:41:24 by jsuppan           #+#    #+#             */
/*   Updated: 2023/08/21 19:59:57 by jsuppan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"
#include <stdint.h>

void	*fdf_memset(void *dst, int value, size_t size)
{
	size_t			i;
	const uint8_t	byte = (uint8_t)value;
	const uint64_t	qword = (uint64_t)byte << 0 | (uint64_t)byte << 8
		| (uint64_t)byte << 16 | (uint64_t)byte << 24
		| (uint64_t)byte << 32 | (uint64_t)byte << 40
		| (uint64_t)byte << 48 | (uint64_t)byte << 56;

	i = 0;
	while (i + sizeof(uint64_t) <= size)
	{
		(*(uint64_t *)(dst + i)) = qword;
		i += sizeof(uint64_t);
	}
	while (i + sizeof(uint8_t) <= size)
	{
		(*(uint8_t *)(dst + i)) = byte;
		i += sizeof(uint8_t);
	}
	return (dst);
}

void	*fdf_memset64(void *dst, uint64_t value, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i + sizeof(uint64_t) <= size)
	{
		(*(uint64_t *)(dst + i)) = value;
		i += sizeof(uint64_t);
	}
	j = 0;
	while (i + j < size)
	{
		(*(uint8_t *)(dst + i + j)) = (value >> (48 - (j * 8))) | 0xff;
		j++;
	}
	return (dst);
}

void	*fdf_memcpy(void *dst, void *src, size_t size)
{
	size_t	i;

	i = 0;
	while (i + sizeof(uint64_t) <= size)
	{
		(*(uint64_t *)(dst + i)) = (*(uint64_t *)(src + i));
		i += sizeof(uint64_t);
	}
	while (i + sizeof(uint8_t) <= size)
	{
		(*(uint8_t *)(dst + i)) = (*(uint8_t *)(src + i));
		i += sizeof(uint8_t);
	}
	return (dst);
}
