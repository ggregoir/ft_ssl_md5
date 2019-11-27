/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ispunct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 18:57:30 by ggregoir          #+#    #+#             */
/*   Updated: 2019/11/27 23:15:34 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "char.h"

int		ft_ispunct(int c)
{
	if (ft_isprint(c) && !(ft_isalnum(c) || c == ' '))
		return (1);
	return (0);
}
