/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 19:05:20 by jafaghpo          #+#    #+#             */
/*   Updated: 2019/06/09 19:05:21 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_vdprintf(int fd, char *format, va_list arg)
{
	int		done;
	int		ret;
	char	*tmp;

	dpf_init_buff(fd);
	g_pf_buff = dpf_buff;
	done = 0;
	tmp = format;
	while (*format)
	{
		if (*format == '%')
		{
			g_pf_buff(tmp, format - tmp);
			done += format - tmp;
			ret = pf_conv(&format, arg);
			done += ret;
			tmp = format + 1;
		}
		format++;
	}
	g_pf_buff(tmp, format - tmp);
	done += format - tmp;
	dpf_putbuff();
	return (done);
}
