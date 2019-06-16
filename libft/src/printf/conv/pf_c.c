/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 19:03:15 by jafaghpo          #+#    #+#             */
/*   Updated: 2019/06/09 19:03:15 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_c(va_list arg, t_pfflags *flags)
{
	char	c;

	c = va_arg(arg, int);
	flags->blank -= 1;
	flags->blank *= (flags->blank <= INT_MAX);
	if (!flags->tags.minus)
	{
		pf_fill(flags->blank, ' ');
		g_pf_buff(&c, 1);
	}
	else
	{
		g_pf_buff(&c, 1);
		pf_fill(flags->blank, ' ');
	}
	return (flags->blank + 1);
}
