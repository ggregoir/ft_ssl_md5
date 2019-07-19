/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 23:14:36 by ggregoir          #+#    #+#             */
/*   Updated: 2019/07/19 01:55:23 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void		update_hash_pre(t_sha256 *hash)
{
	hash->hh0 = hash->h0;
    hash->hh1 = hash->h1;
    hash->hh2 = hash->h2;
    hash->hh3 = hash->h3;
    hash->hh4 = hash->h4;
    hash->hh5 = hash->h5;
    hash->hh6 = hash->h6;
    hash->hh7 = hash->h7;
}

static void		update_hash_post(t_sha256 *hash)
{
	hash->h0 += hash->hh0;
    hash->h1 += hash->hh1;
    hash->h2 += hash->hh2;
    hash->h3 += hash->hh3;
    hash->h4 += hash->hh4;
    hash->h5 += hash->hh5;
    hash->h6 += hash->hh6;
    hash->h7 += hash->hh7;
}

void			sha256_encrypt(t_sha256 *hash, unsigned int *w)
{
	unsigned int i;

	i = 0;
	while (i < 64)
	{
		hash->t1 = rotate_right(hash->hh4, 6) ^ rotate_right(hash->hh4, 11)
			^ rotate_right(hash->hh4, 25);
		hash->ch = (hash->hh4 & hash->hh5) ^ (~hash->hh4 & hash->hh6);
		hash->tmp1 = hash->hh7 + hash->t1 + hash->ch + g_round[i] + w[i];
		hash->t0 = rotate_right(hash->hh0, 2) ^ rotate_right(hash->hh0, 13)
			^ rotate_right(hash->hh0, 22);
		hash->maj = (hash->hh0 & hash->hh1) ^ (hash->hh0 & hash->hh2) ^ (hash->hh1 & hash->hh2);
		hash->tmp2 = hash->t0 + hash->maj;
		hash->hh7 = hash->hh6;
		hash->hh6 = hash->hh5;
		hash->hh5 = hash->hh4;
		hash->hh4 = hash->hh3 + hash->tmp1;
		hash->hh3 = hash->hh2;
		hash->hh2 = hash->hh1;
		hash->hh1 = hash->hh0;
		hash->hh0 = hash->tmp1 + hash->tmp2;
		i++;
	}
	update_hash_post(hash);
}

static void		schedule_array(unsigned int *w, unsigned int *msg, int offset)
{
	unsigned int s0;
	unsigned int s1;
	int i;

	ft_memcpy(w, &msg[offset * 16], 16 * sizeof(uint32_t));
	i = 16;
	while (i < 64)
	{
		s0 = rotate_right(w[i - 15], 7) ^ rotate_right(w[i - 15], 18)
			^ (w[i - 15] >> 3);
		s1 = rotate_right(w[i - 2], 17) ^ rotate_right(w[i - 2], 19)
			^ (w[i - 2] >> 10);
		w[i] = w[i - 16] + s0 + w[i - 7] + s1;
		i++;
	}
}

static void		add_padding(int len, unsigned int *msg)
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

static void		add_size(unsigned int *msg, unsigned int bitlen, unsigned int newlen)
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

void sha256_algo(char *to_hash, int len, t_sha256 *hash)
{
	unsigned int *msg;
	unsigned int newlen;
	unsigned int offset;
	unsigned int bitlen;
	unsigned int w[64];
	unsigned int padding_bitsize;

	bitlen = len * 8;
	offset = 0;
	if (bitlen)
		bitlen += 64;
	newlen = 1 + bitlen / 512;
	padding_bitsize = newlen * 512 - bitlen % 512;
	if (newlen > 1)
		padding_bitsize -= 512 * (newlen - 1);
	if (!(msg = (uint32_t*)ft_memalloc(sizeof(uint32_t) * newlen * 16)))
	{
		ft_printf("MALLOC ERROR\n");
		exit(EXIT_FAILURE);
	}
	ft_memcpy(msg, to_hash, len);
	add_padding(len, msg);
	unsigned int i = 0;
	while (i < newlen * 16)
	{
		msg[i] = swap_bytes_32bit(msg[i]);
		i++;
	}
	add_size(msg, bitlen, newlen);

	while(offset < newlen)
	{
		schedule_array(w, msg, offset);
     	update_hash_pre(hash);
		sha256_encrypt(hash, w);
		offset ++;
	}
	free(msg);
}

void		prompt_sha256(char *to_hash __attribute__((unused)), int8_t *flags __attribute__((unused)))
{
	if (flags['p'])
	{
		flags['p'] = 0;
		to_hash = read_fd(0);
		ft_printf("%s", to_hash);
		print_sha256(to_hash);
		write(1, "\n", 1);
	}
	else
	{
		to_hash = read_fd(0);
		print_sha256(to_hash);
		ft_printf("\n");
		exit(EXIT_SUCCESS);
	}
}

void		sha256(char *to_hash, int8_t *flags __attribute__((unused)))
{
	if (flags['p'])
	{
		sha256_p(to_hash, flags);
	}
	if (flags['q'])
	{
		sha256_q(to_hash, flags);
	}
	else if (flags['r'])
	{
		sha256_r(to_hash, flags);
	}
	else
	{
		sha256_noflag(to_hash, flags);
	}
}