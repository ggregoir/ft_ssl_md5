/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_md5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 22:45:10 by ggregoir          #+#    #+#             */
/*   Updated: 2019/07/19 01:57:54 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void		print_md5(char *to_hash)
{
	size_t		len;
	t_md5		hash;

	hash = (t_md5){0, 0, 0, 0, 0, 0, 0, 0};
	len = ft_strlen(to_hash);
	init_hash_md5(&hash);
	md5_algo(to_hash, len * 8, &hash);
    ft_printf("%.8x%.8x%.8x%.8x", hash.h0, hash.h1, hash.h2, hash.h3);
}

void		md5_p(char *to_hash, int8_t *flags)
{
	char *filename;

	to_hash = 0;
	flags['p'] = 0;
	filename = read_fd(0);
	ft_printf("%s", filename);
	print_md5(filename);
	write(1, "\n", 1);
}

void		md5_q(char *to_hash, int8_t *flags)
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

void		md5_r(char *to_hash, int8_t *flags)
{
	char *filename;

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

void		md5_noflag(char *to_hash, int8_t *flags)
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