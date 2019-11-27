/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 18:58:58 by ggregoir          #+#    #+#             */
/*   Updated: 2019/11/27 23:15:44 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"
#include "type.h"

void	ft_memset(void *data, int octet, size_t len)
{
	t_int64		octet64;

	octet64 = octet | (octet << 8);
	octet64 |= (octet64 << 16);
	octet64 |= (octet64 << 32);
	while (len >= 8)
	{
		*((t_uint64 *)data) = octet64;
		data = (void *)((t_uint64 *)data + 1);
		len -= 8;
	}
	while (len > 0)
	{
		*((t_uint8 *)data) = octet;
		data = (void *)((t_uint8 *)data + 1);
		len -= 1;
	}
}
