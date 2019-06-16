/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_u2short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 19:06:36 by jafaghpo          #+#    #+#             */
/*   Updated: 2019/06/09 19:06:36 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_uint64	pf_u2short(va_list arg)
{
	t_uint64 n;

	n = va_arg(arg, t_uint32);
	n = (t_uint8)n;
	return (n);
}