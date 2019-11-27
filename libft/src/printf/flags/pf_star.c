/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_star.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 19:05:00 by ggregoir          #+#    #+#             */
/*   Updated: 2019/11/27 23:14:54 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pf_star(char *format, va_list arg, t_pfflags *flags)
{
	if (*(format - 1) == '.')
	{
		flags->prec = va_arg(arg, t_uint32);
		flags->tags.prec = 1;
	}
	else
		flags->blank = va_arg(arg, t_uint32);
	return (format + 1);
}
