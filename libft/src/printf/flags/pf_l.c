/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_l.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 19:04:48 by jafaghpo          #+#    #+#             */
/*   Updated: 2019/06/09 19:04:48 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pf_l(char *format, va_list arg, t_pfflags *flags)
{
	(void)arg;
	if (flags->type == L)
		flags->type = LL;
	else
		flags->type = L;
	return (format + 1);
}
