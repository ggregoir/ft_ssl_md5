/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 19:01:50 by jafaghpo          #+#    #+#             */
/*   Updated: 2019/06/09 19:01:51 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"
#include <stdlib.h>

char	*ft_strtrim(const char *s)
{
	char	*tmp;
	size_t	i;
	size_t	j;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	j = ft_strlen(s) - 1;
	while (s[j] == ' ' || s[j] == '\t' || s[j] == '\n')
		j--;
	tmp = ft_strsub(s, i, j - i + 1);
	if (tmp == NULL)
	{
		if (!(tmp = (char *)malloc(1)))
			return (NULL);
		*tmp = '\0';
	}
	return (tmp);
}
