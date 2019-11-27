/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 19:05:17 by ggregoir          #+#    #+#             */
/*   Updated: 2019/11/27 23:14:56 by ggregoir         ###   ########.fr       */
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
