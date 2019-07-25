/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 22:42:41 by ggregoir          #+#    #+#             */
/*   Updated: 2019/07/25 15:58:47 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

uint32_t	rotate_right(uint32_t x, uint32_t c)
{
	return ((x >> c) | (x << (32 - c)));
}

uint32_t	rotate_left(uint32_t x, uint32_t c)
{
	return ((x << c) | (x >> (32 - c)));
}

uint32_t	swap_bytes_32bit(uint32_t val)
{
	val = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0xFF00FF);
	return (val << 16) | (val >> 16);
}
