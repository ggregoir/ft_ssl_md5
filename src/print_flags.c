/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 20:09:16 by ggregoir          #+#    #+#             */
/*   Updated: 2019/08/12 22:42:27 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void	print_hash(char *to_hash, char *hash)
{
	if (ft_strequ(hash, "MD5"))
	{
		print_md5(to_hash);
	}
	if (ft_strequ(hash, "SHA256"))
	{
		print_sha256(to_hash);
	}
}

void		print_p(char *to_hash, int8_t *flags, char *hash)
{
	char *filename;

	to_hash = 0;
	flags['p'] = 0;
	filename = read_fd(0);
	ft_printf("%s", filename);
	print_hash(filename, hash);
	write(1, "\n", 1);
}

void		print_q(char *to_hash, int8_t *flags, char *hash)
{
	int fd;

	if (flags['s'])
	{
		print_hash(to_hash, hash);
		write(1, "\n", 1);
	}
	else
	{
		if ((fd = get_file(to_hash)) != -1)
		{
			to_hash = read_fd(fd);
			print_hash(to_hash, hash);
			write(1, "\n", 1);
			free(to_hash);
		}
	}
}

void		print_r(char *to_hash, int8_t *flags, char *hash)
{
	int		fd;
	char	*filename;

	if (flags['s'])
	{
		print_hash(to_hash, hash);
		ft_printf(" \"%s\"\n", to_hash);
	}
	else
	{
		filename = to_hash;
		if ((fd = get_file(to_hash)) != -1)
		{
			to_hash = read_fd(fd);
			print_hash(to_hash, hash);
			ft_printf(" %s\n", filename);
			free(to_hash);
		}
	}
}

void		print_noflag(char *to_hash, int8_t *flags, char *hash)
{
	int		fd;
	char	*filename;

	if (flags['s'])
	{
		ft_printf("%s (\"%s\") = ", hash, to_hash);
		print_hash(to_hash, hash);
		ft_printf("\n");
	}
	else
	{
		filename = to_hash;
		if ((fd = get_file(to_hash)) != -1)
		{
			to_hash = read_fd(fd);
			ft_printf("%s (%s) = ", hash, filename);
			print_hash(to_hash, hash);
			ft_printf("\n");
			free(to_hash);
		}
	}
}
