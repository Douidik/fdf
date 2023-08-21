/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuppan <jsuppan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 20:40:45 by jsuppan           #+#    #+#             */
/*   Updated: 2023/08/21 20:00:09 by jsuppan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEM_H
# define MEM_H

# include <stddef.h>
# include <stdint.h>

void	*fdf_memset(void *dst, int value, size_t size);
void	*fdf_memset64(void *dst, uint64_t value, size_t size);
void	*fdf_memcpy(void *dst, void *src, size_t size);

#endif
