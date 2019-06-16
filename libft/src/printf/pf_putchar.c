/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 19:05:52 by jafaghpo          #+#    #+#             */
/*   Updated: 2019/06/09 19:05:52 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_return(void *c, int ret)
{
	g_pf_buff(c, ret);
	return (ret);
}

int			pf_putchar(wchar_t c)
{
	unsigned int	octet;

	if (!(c >> 7))
		return (ft_return(&c, 1));
	if (!(c >> 11))
	{
		octet = (((c & 0x3f) << 8) | (c >> 6)) | 0x80c0;
		return (ft_return(&octet, 2));
	}
	if (!(c >> 16))
	{
		octet = (((c & 0x3f) << 16) | (((c >> 6) & 0x3f) << 8)
				| (c >> 12)) | 0x8080e0;
		return (ft_return(&octet, 3));
	}
	if (!(c >> 21))
	{
		octet = (((((c & 0x3f) << 24) | (((c >> 6) & 0x3f) << 16))
				| (((c >> 12) & 0x3f) << 8)) | (c >> 18)) | 0x808080f0;
		return (ft_return(&octet, 4));
	}
	return (-1);
}
