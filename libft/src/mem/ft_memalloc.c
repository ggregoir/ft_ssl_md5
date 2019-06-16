/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 18:58:39 by jafaghpo          #+#    #+#             */
/*   Updated: 2019/06/09 18:58:40 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"
#include <stdlib.h>

void	*ft_memalloc(size_t n)
{
	void	*tmp;

	if (!(tmp = malloc(n)))
		return (NULL);
	ft_bzero(tmp, n);
	return (tmp);
}
