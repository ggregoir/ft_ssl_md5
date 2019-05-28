/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 17:55:58 by ggregoir          #+#    #+#             */
/*   Updated: 2019/05/28 17:37:01 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void		print_usage()
{
	ft_putendl("usage: ft_ssl command [command opts] [command args]");
}

void		print_usage_ssl()
{
	ft_putendl("Standard commands\n");
	ft_putendl("Message Digest commands\nmd5\nsha256\n");
	ft_putendl("Cipher commands\n");
}

void		illegal_option(char c)
{
	ft_putstr("md5: illegal option -- ");
	ft_putchar(c);
	ft_putendl("");
	exit(1);
}

void ft_ssl_error(char *command)
{
	ft_putstr("ft_ssl: Error: '");
	ft_putstr(command);
	ft_putendl("' is an invalid command.\n");
}