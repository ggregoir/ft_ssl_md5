/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 20:25:01 by ggregoir          #+#    #+#             */
/*   Updated: 2019/07/25 18:47:46 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void			prompt_md5(char *to_hash, int8_t *flags)
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

void			md5(char *to_hash, int8_t *flags)
{
	if (flags['p'])
	{
		md5_p(to_hash, flags);
	}
	if (flags['q'])
	{
		md5_q(to_hash, flags);
	}
	else if (flags['r'])
	{
		md5_r(to_hash, flags);
	}
	else
	{
		md5_noflag(to_hash, flags);
	}
}
