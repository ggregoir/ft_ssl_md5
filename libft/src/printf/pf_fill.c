/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 19:05:45 by jafaghpo          #+#    #+#             */
/*   Updated: 2019/06/09 19:05:46 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_fill(int size, char octet)
{
	char	tab[size];

	ft_memset(tab, octet, size);
	g_pf_buff(tab, size);
}
