/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_h.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 19:04:40 by jafaghpo          #+#    #+#             */
/*   Updated: 2019/06/09 19:04:40 by jafaghpo         ###   ########.fr       */
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
