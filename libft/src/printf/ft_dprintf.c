/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 19:05:11 by ggregoir          #+#    #+#             */
/*   Updated: 2019/11/27 23:14:55 by ggregoir         ###   ########.fr       */
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
