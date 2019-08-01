/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sha256.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 22:33:18 by ggregoir          #+#    #+#             */
/*   Updated: 2019/08/02 00:40:13 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void		print_sha256(char *to_hash)
{
	uint32_t	len;
	t_sha256	h;

	ft_bzero(&h, sizeof(h));
	if (to_hash == 0)
		len = 0;
	else
		len = ft_strlen(to_hash);
	init_hash_sha256(&h);
	sha256_algo(to_hash, len, &h);
	ft_printf("%.8x%.8x%.8x%.8x%.8x%.8x%.8x%.8x", h.h0, h.h1, h.h2, h.h3,
		h.h4, h.h5, h.h6, h.h7);
}

void		sha256_p(char *to_hash, int8_t *flags)
{
	char *filename;

	to_hash = 0;
	flags['p'] = 0;
	filename = read_fd(0);
	ft_printf("%s", filename);
	print_sha256(filename);
	write(1, "\n", 1);
}

void		sha256_q(char *to_hash, int8_t *flags)
{
	int fd;

	if (flags['s'])
	{
		print_sha256(to_hash);
		write(1, "\n", 1);
	}
	else
	{
		if ((fd = get_file(to_hash)) != -1)
		{
			to_hash = read_fd(fd);
			print_sha256(to_hash);
			write(1, "\n", 1);
			free(to_hash);
		}
	}
}

void		sha256_r(char *to_hash, int8_t *flags)
{
	char	*filename;
	int		fd;

	if (flags['s'])
	{
		print_sha256(to_hash);
		ft_printf(" \"%s\"\n", to_hash);
	}
	else
	{
		filename = to_hash;
		if ((fd = get_file(to_hash)) != -1)
		{
			to_hash = read_fd(fd);
			print_sha256(to_hash);
			ft_printf(" %s\n", filename);
			free(to_hash);
		}
	}
}

void		sha256_noflag(char *to_hash, int8_t *flags)
{
	char	*filename;
	int		fd;

	if (flags['s'])
	{
		ft_printf("SHA256(\"%s\")= ", to_hash);
		print_sha256(to_hash);
		ft_printf("\n");
	}
	else
	{
		filename = to_hash;
		if ((fd = get_file(to_hash)) != -1)
		{
			to_hash = read_fd(fd);
			ft_printf("SHA256(%s)= ", filename);
			print_sha256(to_hash);
			ft_printf("\n");
			free(to_hash);
		}
	}
}
