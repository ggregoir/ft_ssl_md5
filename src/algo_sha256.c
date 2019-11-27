/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sha256.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 18:46:35 by ggregoir          #+#    #+#             */
/*   Updated: 2019/11/28 00:04:36 by ggregoir         ###   ########.fr       */
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

void			sha256_encrypt(t_sha256 *hash, uint32_t *w)
{
	uint32_t i;

	i = 0;
	while (i < 64)
	{
		hash->t1 = rotate_right(hash->hh4, 6) ^ rotate_right(hash->hh4, 11)
			^ rotate_right(hash->hh4, 25);
		hash->ch = (hash->hh4 & hash->hh5) ^ (~hash->hh4 & hash->hh6);
		hash->tmp1 = hash->hh7 + hash->t1 + hash->ch + g_round[i] + w[i];
		hash->t0 = rotate_right(hash->hh0, 2) ^ rotate_right(hash->hh0, 13)
			^ rotate_right(hash->hh0, 22);
		hash->maj = (hash->hh0 & hash->hh1) ^ (hash->hh0 & hash->hh2)
		^ (hash->hh1 & hash->hh2);
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

static void		schedule_array(uint32_t *w, uint32_t *msg, int offset)
{
	uint32_t	s0;
	uint32_t	s1;
	int			i;

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

void			sha256_algo(char *to_hash, uint32_t len, t_sha256 *hash)
{
	uint32_t *msg;
	uint32_t newlen;
	uint32_t bitlen;
	uint32_t w[64];
	uint32_t i;

	i = -1;
	msg = init_msg(&bitlen, &newlen, &len);
	ft_memcpy(msg, to_hash, len);
	add_padding(len, msg);
	while (++i < newlen * 16)
		msg[i] = swap_bytes_32bit(msg[i]);
	add_size(msg, bitlen, newlen);
	len = 0;
	while (len < newlen)
	{
		schedule_array(w, msg, len);
		update_hash_pre(hash);
		sha256_encrypt(hash, w);
		len++;
	}
	free(msg);
}
