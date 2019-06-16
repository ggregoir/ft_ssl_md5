/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 19:05:17 by jafaghpo          #+#    #+#             */
/*   Updated: 2019/06/09 19:05:18 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_sprintf(char *str, char *format, ...)
{
	va_list	arg;
	int		done;

	va_start(arg, format);
	done = ft_vsprintf(str, format, arg);
	va_end(arg);
	return (done);
}
