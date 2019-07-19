/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 22:42:41 by ggregoir          #+#    #+#             */
/*   Updated: 2019/07/18 20:36:19 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

unsigned int	rotate_right(unsigned int x, unsigned int c)
{
	return ((x >> c) | (x << (32 - c)));
}

unsigned int	rotate_left(unsigned int x, unsigned int c)
{
	return ((x << c) | (x >> (32 - c)));
}

unsigned int	swap_bytes_32bit(unsigned int val)
{
	val = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0xFF00FF);
	return (val << 16) | (val >> 16);
}
