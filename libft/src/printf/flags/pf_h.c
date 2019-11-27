/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_h.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 19:04:40 by ggregoir          #+#    #+#             */
/*   Updated: 2019/11/27 23:14:49 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pf_h(char *format, va_list arg, t_pfflags *flags)
{
	(void)arg;
	if (flags->type == H)
		flags->type = HH;
	else
		flags->type = H;
	return (format + 1);
}
