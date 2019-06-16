/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 19:05:33 by jafaghpo          #+#    #+#             */
/*   Updated: 2019/06/09 19:05:34 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	(*g_f[256])() =
{
	['a'] = pf_a,
	['A'] = pf_maj_a,
	['b'] = pf_b,
	['B'] = pf_maj_b,
	['c'] = pf_c,
	['C'] = pf_maj_c,
	['d'] = pf_d,
	['D'] = pf_maj_d,
	['e'] = pf_e,
	['E'] = pf_maj_e,
	['f'] = pf_f,
	['F'] = pf_maj_f,
	['g'] = pf_g,
	['G'] = pf_maj_g,
	['i'] = pf_i,
	['I'] = pf_maj_i,
	['k'] = pf_k,
	['o'] = pf_o,
	['O'] = pf_maj_o,
	['p'] = pf_p,
	['s'] = pf_s,
	['S'] = pf_maj_s,
	['u'] = pf_u,
	['U'] = pf_maj_u,
	['x'] = pf_x,
	['X'] = pf_maj_x,
	['%'] = pf_per
};

int			pf_arg(char c, va_list arg, t_pfflags *flags)
{
	if (!g_f[(int)c])
		return (-1);
	return (g_f[(int)c](arg, flags));
}
