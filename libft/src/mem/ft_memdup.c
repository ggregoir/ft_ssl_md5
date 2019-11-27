/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 19:39:48 by ggregoir          #+#    #+#             */
/*   Updated: 2019/11/27 23:14:03 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"
#include <stdlib.h>

void	*ft_memdup(void *src, size_t n)
{
	void	*dst;

	if (!(dst = malloc(n)))
		return (NULL);
	ft_memcpy(dst, src, (int)n);
	return (dst);
}
