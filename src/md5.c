/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 20:25:01 by ggregoir          #+#    #+#             */
/*   Updated: 2019/06/27 19:26:35 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

unsigned int	rotate_left(unsigned int x, unsigned int c)
{
	x = (((x) << (c)) | ((x) >> (32 - (c))));
	return (x);
}

void		init_hash(t_md5 *hash)
{
	hash->h0 = 0x67452301;
	hash->h1 = 0xefcdab89;
	hash->h2 = 0x98badcfe;
	hash->h3 = 0x10325476;
}

void		update_hash_post(t_md5 *hash)
{
	hash->hh0 = hash->h0;
    hash->hh1 = hash->h1;
    hash->hh2 = hash->h2;
    hash->hh3 = hash->h3;
}

void		update_hash_past(t_md5 *hash)
{
	hash->h0 += hash->hh0;
    hash->h1 += hash->hh1;
    hash->h2 += hash->hh2;
    hash->h3 += hash->hh3;
}

void			md5_encrypt(t_md5 *hash, unsigned int *w)
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
		//printf("rotateLeft(%x + %x + %x + %x, %d)\n", hash->hh0, f, g_sine[i], w[g], g_shifts[i]);
		hash->hh1 = hash->hh1 + rotate_left(hash->hh0 + f + g_sine[i] + w[g], g_shifts[i]);
		hash->hh0 = tmp;
		i++;
	}
	update_hash_past(hash);
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
		md5_encrypt(hash, w);
		offset += 64;
	}
	free(msg);
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
	char *filename;

	if (flags['p'])
	{
		flags['p'] = 0;
		filename = read_fd(0);
		ft_printf("%s", filename);
		print_md5(filename);
		write(1, "\n", 1);
	}
	if (flags['q'])
	{
		if (flags['s'])
		{
			print_md5(to_hash);
			write(1, "\n", 1);
		}
		else
		{
			if ((to_hash = get_file(to_hash)) != NULL)
			{
				print_md5(to_hash);
				write(1, "\n", 1);
			}
		}
	}
	else if (flags['r'])
	{
		if (flags['s'])
		{
			print_md5(to_hash);
			ft_printf(" \"%s\"\n", to_hash);
		}
		else
		{
			filename = to_hash;
			if ((to_hash = get_file(to_hash)) != NULL)
			{
				print_md5(to_hash);
				ft_printf(" %s\n", filename);
			}
		}
	}
	else
	{
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
}