/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 19:01:35 by jafaghpo          #+#    #+#             */
/*   Updated: 2019/06/09 19:01:35 by jafaghpo         ###   ########.fr       */
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
