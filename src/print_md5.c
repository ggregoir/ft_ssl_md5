/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_md5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 22:45:10 by ggregoir          #+#    #+#             */
/*   Updated: 2019/09/17 23:03:22 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void		print_md5(char *to_hash, size_t len)
{
	t_md5			hash;
	unsigned char	*p;

	hash = (t_md5){0, 0, 0, 0, 0, 0, 0, 0};
	if (to_hash == 0)
		len = 0;
	init_hash_md5(&hash);
	md5_algo(to_hash, len * 8, &hash);
	p = (unsigned char *)&hash.h0;
	ft_printf("%2.2x%2.2x%2.2x%2.2x", p[0], p[1], p[2], p[3]);
	p = (unsigned char *)&hash.h1;
	ft_printf("%2.2x%2.2x%2.2x%2.2x", p[0], p[1], p[2], p[3]);
	p = (unsigned char *)&hash.h2;
	ft_printf("%2.2x%2.2x%2.2x%2.2x", p[0], p[1], p[2], p[3]);
	p = (unsigned char *)&hash.h3;
	ft_printf("%2.2x%2.2x%2.2x%2.2x", p[0], p[1], p[2], p[3]);
}
