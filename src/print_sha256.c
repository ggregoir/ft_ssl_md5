/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sha256.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 22:33:18 by ggregoir          #+#    #+#             */
/*   Updated: 2019/11/28 00:02:53 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void		print_sha256(char *to_hash, size_t len)
{
	t_sha256	h;

	ft_bzero(&h, sizeof(h));
	if (to_hash == 0)
		len = 0;
	init_hash_sha256(&h);
	sha256_algo(to_hash, len, &h);
	ft_printf("%.8x%.8x%.8x%.8x%.8x%.8x%.8x%.8x", h.h0, h.h1, h.h2, h.h3,
		h.h4, h.h5, h.h6, h.h7);
}
