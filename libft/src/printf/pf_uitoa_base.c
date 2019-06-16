/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 19:05:58 by jafaghpo          #+#    #+#             */
/*   Updated: 2019/06/09 19:05:58 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	pf_get_char(t_uint64 n, int maj)
{
	return (n + '0' + (('a' + ('A' - 'a') * maj - '0') - 10) * (n >= 10));
}

int			pf_uitoa_base(char *str, t_uint64 n, t_uint32 base, int maj)
{
	t_uint64	div;
	int			size;
	int			i;

	size = 1;
	div = 1;
	while (div <= n / base)
	{
		div *= base;
		size++;
	}
	i = 0;
	while (div > 0)
	{
		str[i] = pf_get_char(n / div, maj);
		n %= div;
		div /= base;
		i++;
	}
	return (size);
}
