/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_prec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 19:04:55 by jafaghpo          #+#    #+#             */
/*   Updated: 2019/06/09 19:04:56 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pf_prec(char *format, va_list arg, t_pfflags *flags)
{
	int		n;

	(void)arg;
	format++;
	n = 0;
	while (*format >= '0' && *format <= '9')
	{
		n = n * 10 + *format - '0';
		format++;
	}
	flags->prec = n;
	flags->tags.prec = 1;
	return (format);
}
