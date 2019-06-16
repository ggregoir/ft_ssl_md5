/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_tags.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 19:05:55 by jafaghpo          #+#    #+#             */
/*   Updated: 2019/06/09 19:05:55 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*(*g_f[256])(char *, va_list, t_pfflags *) =
{
	['#'] = pf_hashtag,
	['0'] = pf_zero,
	['-'] = pf_minus,
	[' '] = pf_space,
	['+'] = pf_plus,
	['h'] = pf_h,
	['l'] = pf_l,
	['j'] = pf_j,
	['z'] = pf_z,
	['1'] = pf_blank,
	['2'] = pf_blank,
	['3'] = pf_blank,
	['4'] = pf_blank,
	['5'] = pf_blank,
	['6'] = pf_blank,
	['7'] = pf_blank,
	['8'] = pf_blank,
	['9'] = pf_blank,
	['.'] = pf_prec,
	['*'] = pf_star
};

char		*pf_tags(char *format, va_list arg, t_pfflags *flags)
{
	while (g_f[(int)*format])
		format = g_f[(int)*format](format, arg, flags);
	return (format);
}
