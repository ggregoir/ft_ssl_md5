/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 20:09:16 by ggregoir          #+#    #+#             */
/*   Updated: 2019/11/27 23:40:42 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void	print_hash(char *to_hash, char *hash, size_t len)
{
	if (ft_strequ(hash, "MD5"))
	{
		print_md5(to_hash, len);
	}
	if (ft_strequ(hash, "SHA256"))
	{
		print_sha256(to_hash, len);
	}
}

void		print_p(char *to_hash, int8_t *flags, char *hash)
{
	char	*filename;
	size_t	len;

	to_hash = 0;
	flags['p'] = 0;
	filename = read_fd(0, &len);
	write(1, filename, len);
	print_hash(filename, hash, len);
	write(1, "\n", 1);
}

void		print_q(char *to_hash, int8_t *flags, char *hash)
{
	int		fd;
	size_t	len;

	if (flags['s'])
	{
		print_hash(to_hash, hash, ft_strlen(to_hash));
		write(1, "\n", 1);
	}
	else
	{
		if ((fd = get_file(to_hash)) != -1)
		{
			to_hash = read_fd(fd, &len);
			print_hash(to_hash, hash, len);
			write(1, "\n", 1);
			free(to_hash);
		}
	}
}

void		print_r(char *to_hash, int8_t *flags, char *hash)
{
	int		fd;
	char	*filename;
	size_t	len;

	if (flags['s'])
	{
		print_hash(to_hash, hash, ft_strlen(to_hash));
		ft_printf(" \"%s\"\n", to_hash);
	}
	else
	{
		filename = to_hash;
		if ((fd = get_file(to_hash)) != -1)
		{
			to_hash = read_fd(fd, &len);
			print_hash(to_hash, hash, len);
			ft_printf(" %s\n", filename);
			free(to_hash);
		}
	}
}

void		print_noflag(char *to_hash, int8_t *flags, char *hash)
{
	int		fd;
	char	*filename;
	size_t	len;

	if (flags['s'])
	{
		ft_printf("%s (\"%s\") = ", hash, to_hash);
		print_hash(to_hash, hash, ft_strlen(to_hash));
		ft_printf("\n");
	}
	else
	{
		filename = to_hash;
		if ((fd = get_file(to_hash)) != -1)
		{
			to_hash = read_fd(fd, &len);
			ft_printf("%s (%s) = ", hash, filename);
			print_hash(to_hash, hash, len);
			ft_printf("\n");
			free(to_hash);
		}
	}
}
