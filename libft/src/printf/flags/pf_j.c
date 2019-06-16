/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_j.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 19:04:45 by jafaghpo          #+#    #+#             */
/*   Updated: 2019/06/09 19:04:45 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pf_j(char *format, va_list arg, t_pfflags *flags)
{
	(void)arg;
	flags->type = J;
	return (format + 1);
}
