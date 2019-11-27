/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_maj_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 19:04:03 by ggregoir          #+#    #+#             */
/*   Updated: 2019/11/27 23:14:42 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_maj_s(va_list arg, t_pfflags *flags)
{
	wchar_t		*str;
	t_uint32	size;

	str = va_arg(arg, wchar_t *);
	size = ft_wstrlen(str);
	flags->blank -= size;
	flags->blank *= (flags->blank <= INT_MAX);
	if (!flags->tags.minus)
	{
		pf_fill(flags->blank, ' ');
		while (*str)
			pf_putchar(*str++);
	}
	else
	{
		while (*str)
		{
			pf_putchar(*str);
			str++;
		}
		pf_fill(flags->blank, ' ');
	}
	return (size + flags->blank);
}
