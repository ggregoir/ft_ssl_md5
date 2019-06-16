/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_star.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 19:05:00 by jafaghpo          #+#    #+#             */
/*   Updated: 2019/06/09 19:05:01 by jafaghpo         ###   ########.fr       */
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
