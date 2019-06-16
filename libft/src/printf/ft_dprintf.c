/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 19:05:11 by jafaghpo          #+#    #+#             */
/*   Updated: 2019/06/09 19:05:12 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_dprintf(int fd, char *format, ...)
{
	va_list arg;
	int		done;

	va_start(arg, format);
	done = ft_vdprintf(fd, format, arg);
	va_end(arg);
	return (done);
}
