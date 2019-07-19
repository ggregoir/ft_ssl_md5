/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 20:25:01 by ggregoir          #+#    #+#             */
/*   Updated: 2019/07/19 02:05:07 by ggregoir         ###   ########.fr       */
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

static void		md5_shifts(t_md5 *hash, unsigned int *f,unsigned int *g, int i)
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

void			md5_encrypt(t_md5 *hash, unsigned int *w)
{
	unsigned int f;
	unsigned int g;
	int i;
	unsigned int tmp;

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
		hash->hh1 = hash->hh1 + rotate_left(hash->hh0 + f + g_sine[i] + w[g], g_shifts[i]);
		hash->hh0 = tmp;
		i++;
	}
	hash->h0 += hash->hh0;
    hash->h1 += hash->hh1;
    hash->h2 += hash->hh2;
    hash->h3 += hash->hh3;
}

void md5_algo(char *to_hash, int len, t_md5 *hash)
{
	unsigned char *msg;
	int newlen;
	unsigned int *w;

	newlen = (len + 1);
	while (newlen%512 != 448)
		newlen++;
	newlen /= 8;
	if (!(msg = ft_memalloc(newlen + 64)))
	{
		ft_printf("MALLOC ERROR\n");
		exit(EXIT_FAILURE);
	}
	ft_memcpy(msg, to_hash, len);
	msg[len] = 128;
	ft_memcpy(msg + newlen, &len, 4);
	len = 0;
	while(len < newlen)
	{
		w = (unsigned int *)(msg + len);
     	update_hash_pre(hash);
		md5_encrypt(hash, w);
		len += 64;
	}
	free(msg);
}

void		prompt_md5(char *to_hash __attribute__((unused)), int8_t *flags __attribute__((unused)))
{
	if (flags['p'])
	{
		flags['p'] = 0;
		to_hash = read_fd(0);
		ft_printf("%s", to_hash);
		print_md5(to_hash);
		write(1, "\n", 1);
	}
	else
	{
		to_hash = read_fd(0);
		print_md5(to_hash);
		ft_printf("\n");
		exit(EXIT_SUCCESS);
	}
}

void		md5(char *to_hash, int8_t *flags __attribute__((unused)))
{
	if (flags['p'])
	{
		md5_p(to_hash, flags);
	}
	if (flags['q'])
	{
		md5_q(to_hash, flags);
	}
	else if (flags['r'])
	{
		md5_r(to_hash, flags);
	}
	else
	{
		md5_noflag(to_hash, flags);
	}
}