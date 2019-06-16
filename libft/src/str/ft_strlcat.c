/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 19:00:12 by jafaghpo          #+#    #+#             */
/*   Updated: 2019/06/09 19:00:13 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*dst_cpy;
	char	*src_cpy;
	size_t	i;
	size_t	len;

	dst_cpy = dst;
	src_cpy = (char *)src;
	i = size;
	while (i-- != 0 && *dst_cpy != '\0')
		dst_cpy++;
	len = dst_cpy - dst;
	i = size - len;
	if (i == 0)
		return (len + ft_strlen(src_cpy));
	while (*src_cpy != '\0')
	{
		if (i != 1)
		{
			*dst_cpy++ = *src_cpy;
			i--;
		}
		src_cpy++;
	}
	*dst_cpy = '\0';
	return (len + (src_cpy - src));
}
