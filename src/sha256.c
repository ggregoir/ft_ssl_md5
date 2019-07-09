/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 23:14:36 by ggregoir          #+#    #+#             */
/*   Updated: 2019/07/09 23:33:15 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

unsigned int	rotate_right(unsigned int x, unsigned int c)
{
	return ((x >> c) | (x << (32 - c)));
}

unsigned int	swap_bytes_32bit(unsigned int val)
{
	val = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0xFF00FF);
	return (val << 16) | (val >> 16);
}

static void		init_hash(t_sha256 *hash)
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
	/*while (i < 64)
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
	}*/

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

	/*
	while (i < 64)
	{
		m->t1 = right_rotate(m->e, 6) ^ right_rotate(m->e, 11)
			^ right_rotate(m->e, 25);
		m->ch = (m->e & m->f) ^ (~m->e & m->g);
		m->temp1 = m->h + m->t1 + m->ch + g_cube[i] + m->w[i];
		m->t0 = right_rotate(m->a, 2) ^ right_rotate(m->a, 13)
			^ right_rotate(m->a, 22);
		m->maj = (m->a & m->b) ^ (m->a & m->c) ^ (m->b & m->c);
		m->temp2 = m->t0 + m->maj;
		m->h = m->g;
		m->g = m->f;
		m->f = m->e;
		m->e = m->d + m->temp1;
		m->d = m->c;
		m->c = m->b;
		m->b = m->a;
		m->a = m->temp1 + m->temp2;
		i++;
	}
	*/
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

void		print_sha256(char *to_hash)
{
	size_t		len;
	t_sha256	h;

	ft_bzero(&h, sizeof(h));
	len = ft_strlen(to_hash);
	init_hash(&h);
	sha256_algo(to_hash, len, &h);
	ft_printf("%.8x%.8x%.8x%.8x%.8x%.8x%.8x%.8x",h.h0,h.h1,h.h2,h.h3,
		h.h4,h.h5,h.h6,h.h7);
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
	char *filename;

	if (flags['p'])
	{
		flags['p'] = 0;
		filename = read_fd(0);
		ft_printf("%s", filename);
		print_sha256(filename);
		write(1, "\n", 1);
	}
	if (flags['q'])
	{
		if (flags['s'])
		{
			print_sha256(to_hash);
			write(1, "\n", 1);
		}
		else
		{
			if ((to_hash = get_file(to_hash)) != NULL)
			{
				print_sha256(to_hash);
				write(1, "\n", 1);
			}
		}
	}
	else if (flags['r'])
	{
		if (flags['s'])
		{
			print_sha256(to_hash);
			ft_printf(" \"%s\"\n", to_hash);
		}
		else
		{
			filename = to_hash;
			if ((to_hash = get_file(to_hash)) != NULL)
			{
				print_sha256(to_hash);
				ft_printf(" %s\n", filename);
			}
		}
	}
	else
	{
		if (flags['s'])
		{
			ft_printf("SHA256(\"%s\")= ", to_hash);
			print_sha256(to_hash);
			ft_printf("\n");
		}
		else
		{
			filename = to_hash;
			if ((to_hash = get_file(to_hash)) != NULL)
			{
					ft_printf("SHA256(%s)= ", filename);
					print_sha256(to_hash);
					ft_printf("\n");
			}
		}
	}
}