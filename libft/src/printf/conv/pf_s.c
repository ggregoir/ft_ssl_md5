/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 19:04:21 by jafaghpo          #+#    #+#             */
/*   Updated: 2019/06/09 19:04:21 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_s(va_list arg, t_pfflags *flags)
{
	char		*str;
	t_uint32	size;

	str = va_arg(arg, char *);
	size = ft_strlen(str);
	if (flags->tags.prec && flags->prec < size)
		size = flags->prec;
	flags->blank -= size;
	flags->blank *= (flags->blank <= INT_MAX);
	if (!flags->tags.minus)
	{
		pf_fill(flags->blank, ' ');
		g_pf_buff(str, size);
	}
	else
	{
		g_pf_buff(str, size);
		pf_fill(flags->blank, ' ');
	}
	return (size + flags->blank);
}
