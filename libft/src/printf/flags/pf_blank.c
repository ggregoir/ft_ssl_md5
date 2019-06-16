/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_blank.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 19:04:38 by jafaghpo          #+#    #+#             */
/*   Updated: 2019/06/09 19:04:38 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pf_blank(char *format, va_list arg, t_pfflags *flags)
{
	int		n;

	(void)arg;
	n = 0;
	while (*format >= '0' && *format <= '9')
	{
		n = n * 10 + *format - '0';
		format++;
	}
	flags->blank = n;
	return (format);
}
