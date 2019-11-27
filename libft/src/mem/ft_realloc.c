/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 18:59:03 by ggregoir          #+#    #+#             */
/*   Updated: 2019/11/27 23:14:28 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"
#include "put.h"
#include <stdlib.h>

void	*ft_realloc(void *data, size_t size)
{
	void	*tmp;

	if (!(tmp = malloc(size)))
		return (NULL);
	if (!data)
		return (tmp);
	ft_memmove(tmp, data, size);
	free(data);
	return (tmp);
}
