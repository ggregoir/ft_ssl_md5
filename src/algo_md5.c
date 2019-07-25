/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_md5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 18:46:23 by ggregoir          #+#    #+#             */
/*   Updated: 2019/07/25 19:30:58 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void		update_hash_pre(t_md5 *hash)
{
	hash->hh0 = hash->h0;
	hash->hh1 = hash->h1;
	hash->hh2 = hash->h2;
	hash->hh3 = hash->h3;
}

static void		md5_shifts(t_md5 *hash, uint32_t *f, uint32_t *g, int i)
{
	if (i < 16)
	{
		*f = (hash->hh1 & hash->hh2) | ((~hash->hh1) & hash->hh3);
		*g = i;
	}
	else if (i < 32)
	{
		*f = (hash->hh3 & hash->hh1) | ((hash->hh2) & (~hash->hh3));
		*g = (5 * i + 1) % 16;
	}
	else if (i < 48)
	{
		*f = hash->hh1 ^ hash->hh2 ^ hash->hh3;
		*g = (3 * i + 5) % 16;
	}
	else if (i < 64)
	{
		*f = hash->hh2 ^ (hash->hh1 | (~hash->hh3));
		*g = (7 * i) % 16;
	}
}

void			md5_encrypt(t_md5 *hash, uint32_t *w)
{
	uint32_t	f;
	uint32_t	g;
	int			i;
	uint32_t	tmp;

	g = 0;
	i = 0;
	tmp = 0;
	f = 0;
	while (i < 64)
	{
		md5_shifts(hash, &f, &g, i);
		tmp = hash->hh3;
		hash->hh3 = hash->hh2;
		hash->hh2 = hash->hh1;
		hash->hh1 = hash->hh1 + rotate_left(hash->hh0 + f + g_sine[i] + w[g],
			g_shifts[i]);
		hash->hh0 = tmp;
		i++;
	}
	hash->h0 += hash->hh0;
	hash->h1 += hash->hh1;
	hash->h2 += hash->hh2;
	hash->h3 += hash->hh3;
}

void			md5_algo(char *to_hash, int len, t_md5 *hash)
{
	unsigned char	*msg;
	int				newlen;
	uint32_t		*w;

	newlen = (len + 1);
	while (newlen % 512 != 448)
		newlen++;
	newlen /= 8;
	if (!(msg = ft_memalloc(newlen + 64)))
	{
		ft_printf("MALLOC ERROR\n");
		exit(EXIT_FAILURE);
	}
	ft_memcpy(msg, to_hash, len / 8);
	msg[len / 8] = 128;
	ft_memcpy(msg + newlen, &len, 4);
	len = 0;
	while (len < newlen)
	{
		w = (uint32_t *)(msg + len);
		update_hash_pre(hash);
		md5_encrypt(hash, w);
		len += 64;
	}
	free(msg);
}
