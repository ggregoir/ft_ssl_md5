/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 19:05:49 by ggregoir          #+#    #+#             */
/*   Updated: 2019/11/27 23:15:00 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_itoa(char *str, t_int64 n)
{
	int		size;
	t_int64	div;
	int		i;

	size = 1;
	div = -1;
	while (div >= n / 10)
	{
		div *= 10;
		size++;
	}
	i = 0;
	while (div < 0)
	{
		str[i] = n / div + '0';
		n %= div;
		div /= 10;
		i++;
	}
	return (size);
}
