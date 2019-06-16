/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 19:05:15 by jafaghpo          #+#    #+#             */
/*   Updated: 2019/06/09 19:05:15 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char *format, ...)
{
	va_list	arg;
	int		done;

	va_start(arg, format);
	done = ft_vprintf(format, arg);
	va_end(arg);
	return (done);
}
