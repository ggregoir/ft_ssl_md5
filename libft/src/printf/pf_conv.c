/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 19:05:41 by ggregoir          #+#    #+#             */
/*   Updated: 2019/11/27 23:14:59 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_conv(char **format, va_list arg)
{
	t_pfflags	flags;

	(*format)++;
	ft_bzero(&flags, sizeof(flags));
	flags.type = ND;
	*format = pf_tags(*format, arg, &flags);
	return (pf_arg(**format, arg, &flags));
}
