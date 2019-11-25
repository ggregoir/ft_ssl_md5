/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 23:14:36 by ggregoir          #+#    #+#             */
/*   Updated: 2019/11/21 18:31:12 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void		add_padding(int len, uint32_t *msg)
{
	uint32_t	pad;
	size_t		last_bytes;
	size_t		index;

	last_bytes = len % 4;
	index = len / 4;
	pad = 0x00000080;
	if (last_bytes == 1)
		pad = 0x00008000;
	else if (last_bytes == 2)
		pad = 0x00800000;
	else if (last_bytes == 3)
		pad = 0x80000000;
	else if (last_bytes == 4)
	{
		index++;
	}
	msg[index] = msg[index] | pad;
}

void		add_size(uint32_t *msg, uint32_t bitlen, uint32_t newlen)
{
	size_t		size;
	size_t		index;

	size = 0;
	if (bitlen)
	{
		size = bitlen - 64;
	}
	index = newlen * 16 - 2;
	msg[index] = (size >> 32) & 0xffffffff;
	msg[index + 1] = size & 0xffffffff;
}

uint32_t	*init_msg(uint32_t *bitlen, uint32_t *newlen, uint32_t *len)
{
	uint32_t *msg;

	*bitlen = *len * 8;
	if (*bitlen)
		*bitlen += 64;
	*newlen = 1 + *bitlen / 512;
	if (!(msg = (uint32_t*)ft_memalloc(sizeof(uint32_t) * *newlen * 16)))
	{
		ft_printf("MALLOC ERROR\n");
		exit(EXIT_FAILURE);
	}
	return (msg);
}

void		prompt_sha256(char *to_hash, int8_t *flags)
{
	size_t len;
	if (flags['p'])
	{
		flags['p'] = 0;
		to_hash = read_fd(0, &len);
		ft_printf("%s", to_hash);
		print_sha256(to_hash, len);
		write(1, "\n", 1);
	}
	else
	{
		to_hash = read_fd(0, &len);
		print_sha256(to_hash, len);
		ft_printf("\n");
		ft_memdel((void**)&to_hash);
		exit(EXIT_SUCCESS);
	}
}

void		sha256(char *to_hash, int8_t *flags)
{
	if (flags['p'])
	{
		print_p(to_hash, flags, "SHA256");
	}
	if (flags['q'])
	{
		print_q(to_hash, flags, "SHA256");
	}
	else if (flags['r'])
	{
		print_r(to_hash, flags, "SHA256");
	}
	else
	{
		print_noflag(to_hash, flags, "SHA256");
	}
}
