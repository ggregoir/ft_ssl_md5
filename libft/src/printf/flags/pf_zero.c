/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_zero.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 19:05:05 by jafaghpo          #+#    #+#             */
/*   Updated: 2019/06/09 19:05:06 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pf_zero(char *format, va_list arg, t_pfflags *flags)
{
	(void)arg;
	flags->tags.zero = 1;
	return (format + 1);
}
