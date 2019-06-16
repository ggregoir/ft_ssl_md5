/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 19:39:48 by jafaghpo          #+#    #+#             */
/*   Updated: 2019/06/12 00:47:00 by jafaghpo         ###   ########.fr       */
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
