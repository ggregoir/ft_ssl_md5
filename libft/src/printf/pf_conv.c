/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 19:05:41 by jafaghpo          #+#    #+#             */
/*   Updated: 2019/06/09 19:05:42 by jafaghpo         ###   ########.fr       */
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
