/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 23:14:36 by ggregoir          #+#    #+#             */
/*   Updated: 2019/06/30 23:37:12 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

uint32_t	rotate_right(unsigned int x, unsigned int c)
{
	return (((x) >> (c)) | ((x) << (32 - (c))));
}

void		init_hash(t_sha256 *hash)
{
	hash->h0 = 0x6a09e667;
	hash->h1 = 0xbb67ae85;
	hash->h2 = 0x3c6ef372;
	hash->h3 = 0xa54ff53a;
	hash->h4 = 0x510e527f;
	hash->h5 = 0x9b05688c;
	hash->h6 = 0x1f83d9ab;
	hash->h7 = 0x5be0cd19;
}

void		update_hash_post(t_sha256 *hash)
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

void		update_hash_past(t_sha256 *hash)
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

void			sha256_encrypt(t_md5 *hash, unsigned int *w)
{
	unsigned int f;
	unsigned int g;
	unsigned int i;
	unsigned int tmp;

	g = 0;
	i = 0;
	tmp = 0;
	f = 0;
	while (i < 64)
	{
		if (i < 16)
		{
			f = (hash->hh1 & hash->hh2) | ((~hash->hh1) & hash->hh3);
			g = i;
		}
		else if (i < 32)
		{
			f = (hash->hh3 & hash->hh1) | ((hash->hh2) & (~hash->hh3));
			g = (5 * i + 1) % 16;
		}
		else if (i < 48)
		{
			f = hash->hh1 ^ hash->hh2 ^ hash->hh3;
			g = (3 * i + 5) % 16;
		}
		else if (i < 64)
		{
			f = hash->hh2 ^ (hash->hh1 | (~hash->hh3));
			g = (7 * i) % 16;
		}
		tmp = hash->hh3;
		hash->hh3 = hash->hh2;
		hash->hh2 = hash->hh1;
		hash->hh1 = hash->hh1 + rotate_left(hash->hh0 + f + g_sine[i] + w[g], g_shifts[i]);
		hash->hh0 = tmp;
		i++;
	}
	update_hash_past(hash);
}

static void		schedule_array(t_sha *hash, unsigned int *w)
{
	unsigned int s0;
	unsigned int s1;
	i = 16;
	while (i < 64)
	{
		s0 = right_rotate(w[i - 15], 7) ^ right_rotate(w[i - 15], 18)
			^ (w[i - 15] >> 3);
		s1 = right_rotate(w[i - 2], 17) ^ right_rotate(m->w[i - 2], 19)
			^ (w[i - 2] >> 10);
		w[i] = w[i - 16] + s0 + w[i - 7] + s1;
		i++;
	}
}

void sha256_algo(char *to_hash, int len, t_sha256 *hash)
{
	unsigned char *msg;
	int newlen;
	int offset;
	unsigned int bitlen;
	unsigned int *w;

	bitlen = len * 8;
	newlen = (bitlen + 1);
	offset = 0;
	w = 0;
	while (newlen%512 != 448)
		newlen++;
	newlen /= 8;
	msg = ft_memalloc(newlen + 64);
	ft_memcpy(msg, to_hash, len);
	msg[len] = 128;
	ft_memcpy(msg + newlen, &bitlen, 4);
	while(offset < newlen)
	{
		w = (unsigned int *)(msg + offset);

     	update_hash_post(hash);
		sha256_encrypt(hash, w);
		offset += 64;
	}
	free(msg);
}

void		print_sha256(char *to_hash)
{
	size_t		len;
	t_sha		hash;
	unsigned char *p;

	hash = (t_sha256){0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	len = ft_strlen(to_hash);
	init_hash(&hash);
	md5_algo(to_hash, len, &hash);
	p=(unsigned char *)&hash.h0;
	ft_printf("%2.2x%2.2x%2.2x%2.2x", p[0], p[1], p[2], p[3]);
    p=(unsigned char *)&hash.h1;
	ft_printf("%2.2x%2.2x%2.2x%2.2x", p[0], p[1], p[2], p[3]);
    p=(unsigned char *)&hash.h2;
	ft_printf("%2.2x%2.2x%2.2x%2.2x", p[0], p[1], p[2], p[3]);
    p=(unsigned char *)&hash.h3;
    ft_printf("%2.2x%2.2x%2.2x%2.2x", p[0], p[1], p[2], p[3]);
    p=(unsigned char *)&hash.h4;
	ft_printf("%2.2x%2.2x%2.2x%2.2x", p[0], p[1], p[2], p[3]);
    p=(unsigned char *)&hash.h5;
	ft_printf("%2.2x%2.2x%2.2x%2.2x", p[0], p[1], p[2], p[3]);
    p=(unsigned char *)&hash.h6;
	ft_printf("%2.2x%2.2x%2.2x%2.2x", p[0], p[1], p[2], p[3]);
    p=(unsigned char *)&hash.h7;
    ft_printf("%2.2x%2.2x%2.2x%2.2x", p[0], p[1], p[2], p[3]);
}

void		prompt_sha256(char *to_hash __attribute__((unused)), int8_t *flags __attribute__((unused)))
{
	to_hash = read_fd(0);
	printf("\nje dois hash:%s\n", to_hash);
	exit(EXIT_SUCCESS);
}

void		sha256(char *to_hash, int8_t *flags __attribute__((unused)))
{
	char *filename;

	if (flags['s'])
	{
		printf("SHA256(\"%s\") = steak hashé\n", to_hash);
	}
	else
	{
	filename = to_hash;
	if ((to_hash = get_file(to_hash)) != NULL)
			printf("SHA256(%s) = %s\n", filename, to_hash);
	}
}