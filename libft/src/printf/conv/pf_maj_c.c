/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_maj_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 19:03:43 by jafaghpo          #+#    #+#             */
/*   Updated: 2019/06/09 19:03:43 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	pf_wcharlen(wchar_t c)
{
	if (!(c >> 8))
		return (1);
	if (!(c >> 11))
		return (2);
	if (!(c >> 16))
		return (3);
	return (4);
}

int			pf_maj_c(va_list arg, t_pfflags *flags)
{
	wchar_t	c;
	int		size;

	c = va_arg(arg, wchar_t);
	size = pf_wcharlen(c);
	flags->blank -= size;
	flags->blank *= (flags->blank <= INT_MAX);
	if (!flags->tags.minus)
	{
		pf_fill(flags->blank, ' ');
		pf_putchar(c);
	}
	else
	{
		pf_putchar(c);
		pf_fill(flags->blank, ' ');
	}
	return (size + flags->blank);
}
