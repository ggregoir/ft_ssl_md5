/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 19:01:56 by jafaghpo          #+#    #+#             */
/*   Updated: 2019/06/09 19:01:56 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

wchar_t	*ft_wstrcpy(wchar_t *dest, const wchar_t *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
