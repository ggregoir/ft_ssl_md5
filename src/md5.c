/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 20:25:01 by ggregoir          #+#    #+#             */
/*   Updated: 2019/11/21 18:30:40 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void			prompt_md5(char *to_hash, int8_t *flags)
{
	size_t len;
	if (flags['p'])
	{
		flags['p'] = 0;
		to_hash = read_fd(0, &len);
		ft_printf("%s", to_hash);
		print_md5(to_hash, len);
		write(1, "\n", 1);
	}
	else
	{
		to_hash = read_fd(0, &len);
		print_md5(to_hash, len);
		ft_printf("\n");
		ft_memdel((void**)&to_hash);
		exit(EXIT_SUCCESS);
	}
}

void			md5(char *to_hash, int8_t *flags)
{
	if (flags['p'])
	{
		print_p(to_hash, flags, "MD5");
	}
	if (flags['q'])
	{
		print_q(to_hash, flags, "MD5");
	}
	else if (flags['r'])
	{
		print_r(to_hash, flags, "MD5");
	}
	else
	{
		print_noflag(to_hash, flags, "MD5");
	}
}
