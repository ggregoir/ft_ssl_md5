/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_plus.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 19:04:53 by jafaghpo          #+#    #+#             */
/*   Updated: 2019/06/09 19:04:53 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pf_plus(char *format, va_list arg, t_pfflags *flags)
{
	(void)arg;
	flags->tags.plus = 1;
	return (format + 1);
}
