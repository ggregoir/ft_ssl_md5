/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 18:59:56 by jafaghpo          #+#    #+#             */
/*   Updated: 2019/06/09 18:59:56 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*tmp;
	size_t	i;

	if (!(tmp = (char *)malloc(sizeof(*tmp) * (ft_strlen(s) + 1))))
		return (NULL);
	i = 0;
	while (s[i])
	{
		tmp[i] = ((char *)s)[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
