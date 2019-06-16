/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 19:01:37 by jafaghpo          #+#    #+#             */
/*   Updated: 2019/06/09 19:01:38 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	len;

	len = ft_strlen(s2);
	if (*s2 == '\0')
		return ((char *)s1);
	while (*s1 != '\0' && len <= n)
	{
		if (*s1 == *s2 && ft_strncmp(s1, s2, len) == 0)
			return ((char *)s1);
		s1++;
		n--;
	}
	return (NULL);
}
