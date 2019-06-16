/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 20:25:01 by ggregoir          #+#    #+#             */
/*   Updated: 2019/06/16 20:41:27 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

unsigned int	rotate_left(unsigned int x, unsigned int c)
{
	x = (((x) << (c)) | ((x) >> (32 - (c))));
	return (x);
}

void			md5_encrypt(t_md5 *hash, unsigned int *w)
{
	unsigned int fghi;
	unsigned int g;
	unsigned int i;
	unsigned int tmp;

	g = 0;
	i = 0;
	tmp = 0;
	fghi = 0;
	while (i < 64)
	{
		if (i < 16)
		{
			fghi = (hash->hh1 & hash->hh2) | ((~hash->hh1) & hash->hh3);
			g = i;
		}
		else if (i < 32)
		{
			fghi = (hash->hh3 & hash->hh1) | ((hash->hh2) & (~hash->hh3));
			g = (5 * i + 1) % 16;
		}
		else if (i < 48)
		{
			fghi = hash->hh1 ^ hash->hh2 ^ hash->hh3;
			g = (3 * i + 5) % 16;
		}
		else if (i < 64)
		{
			fghi = hash->hh2 ^ (hash->hh1 | (~hash->hh3));
			g = (7 * i) % 16;
		}
		tmp = hash->hh3;
		hash->hh3 = hash->hh2;
		hash->hh2 = hash->hh1;
		hash->hh1 = hash->hh1 + rotate_left(hash->hh0 + fghi + g_sine[i] + w[g], g_shifts[i]);
		hash->hh0 = tmp;
		i++;
	}
}


void md5_algo(char *to_hash, int len, t_md5 *hash)
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
	{
		newlen++;
	}
	newlen /= 8;
	msg = ft_memalloc(newlen + 64);
	ft_memcpy(msg, to_hash, len);
	msg[len] = 128;
	ft_memcpy(msg + newlen, &bitlen, 4);
	while(offset < newlen)
	{
		w = (unsigned int *)(msg + offset);
		md5_encrypt(hash, w);
		offset += 64;
	}
	free(msg);

}

void		init_hash(t_md5 *hash)
{
	hash->h0 = 0x67452301;
	hash->h1 = 0xefcdab89;
	hash->h2 = 0x98badcfe;
	hash->h3 = 0x10325476;
	hash->hh0 = hash->h0;
	hash->hh1 = hash->h1;
	hash->hh2 = hash->h2;
	hash->hh3 = hash->h3;
}

void		print_md5(char *to_hash)
{
	size_t		len;
	t_md5		hash;
	unsigned char *p;

	hash = (t_md5){0, 0, 0, 0, 0, 0, 0, 0};
	len = ft_strlen(to_hash);
	init_hash(&hash);
	md5_algo(to_hash, len, &hash);
	hash.h0 += hash.hh0;
	hash.h1 += hash.hh1;
	hash.h2 += hash.hh2;
	hash.h3 += hash.hh3;
	p=(unsigned char *)&hash.h0;
	ft_printf("%2.2x%2.2x%2.2x%2.2x", p[0], p[1], p[2], p[3]);
    p=(unsigned char *)&hash.h1;
	ft_printf("%2.2x%2.2x%2.2x%2.2x", p[0], p[1], p[2], p[3]);
    p=(unsigned char *)&hash.h2;
	ft_printf("%2.2x%2.2x%2.2x%2.2x", p[0], p[1], p[2], p[3]);
    p=(unsigned char *)&hash.h3;
    ft_printf("%2.2x%2.2x%2.2x%2.2x", p[0], p[1], p[2], p[3]);
}

void		prompt_md5(char *to_hash __attribute__((unused)), int8_t *flags __attribute__((unused)))
{
	to_hash = read_fd(0);
	print_md5(to_hash);
	ft_printf("\n");

	exit(EXIT_SUCCESS);
}

void		md5(char *to_hash, int8_t *flags __attribute__((unused)))
{
	char *filename;

	if (flags['s'])
	{
		ft_printf("MD5 (\"%s\") = ", to_hash);
		print_md5(to_hash);
		ft_printf("\n");
	}
	else
	{
		filename = to_hash;
		if ((to_hash = get_file(to_hash)) != NULL)
		{
				ft_printf("MD5 (%s) = ", filename);
				print_md5(to_hash);
				ft_printf("\n");
		}
	}
}