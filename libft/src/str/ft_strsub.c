/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 19:01:48 by jafaghpo          #+#    #+#             */
/*   Updated: 2019/06/09 19:01:48 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"
#include <stdlib.h>

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*tmp;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if (!(tmp = (char *)malloc(sizeof(*tmp) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		tmp[i] = s[start + i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
