/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 18:59:03 by jafaghpo          #+#    #+#             */
/*   Updated: 2019/06/11 23:26:22 by jafaghpo         ###   ########.fr       */
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
