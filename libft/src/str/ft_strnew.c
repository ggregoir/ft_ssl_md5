/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 19:01:35 by ggregoir          #+#    #+#             */
/*   Updated: 2019/11/27 23:14:25 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"
#include "mem.h"
#include <stdlib.h>

char	*ft_strnew(size_t n)
{
	char	*tmp;

	if (!(tmp = (char *)malloc(sizeof(*tmp) * (n + 1))))
		return (NULL);
	ft_bzero((void *)tmp, n + 1);
	return (tmp);
}
