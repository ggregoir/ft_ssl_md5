/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 17:55:58 by ggregoir          #+#    #+#             */
/*   Updated: 2019/07/25 16:54:21 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void	print_usage(void)
{
	ft_dprintf(2, "usage: ft_ssl command [command opts] [command args]\n");
}

void		print_usage_ssl(void)
{
	ft_printf("Standard commands\n\n");
	ft_printf("Message Digest commands\nmd5\nsha256\n\n");
	ft_printf("Cipher commands\n\n");
}

void		illegal_option(char c)
{
	ft_dprintf(2, "md5: illegal option -- %c \n", c);
	print_usage();
	exit(EXIT_FAILURE);
}

int			flag_string_error(void)
{
	ft_dprintf(2, "md5: option requires an argument -- s\n");
	print_usage();
	return (1);
}

int			ft_ssl_error(char *command)
{
	ft_dprintf(2, "ft_ssl: Error: '%s' is an invalid command.\n\n", command);
	return (0);
}
