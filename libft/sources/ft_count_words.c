/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 14:41:44 by ggregoir          #+#    #+#             */
/*   Updated: 2019/06/10 19:19:36 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		count_words_spaces(const char *str)
{
	int i;

	i = 0;
	while (*str != '\0')
	{
		while (*str == ' ' || *str == '\t')
			str++;
		if (*str != ' ' && *str != '\t' && *str != '\0')
		{
			while (*str != ' ' && *str != '\t' && *str != '\0')
				str++;
			i++;
		}
	}
	return (i);
}

int		ft_count_words(const char *str, char c)
{
	int i;

	i = 0;
	if (*str == c)
		return (-1);
	while (*str)
	{
		while (*str && *str != c)
			str++;
		if (*str == c)
		{
			str++;
			if (*str == c)
				return (-1);
		}
		i++;
	}
	if (*str == c)
		return (-1);
	return (i);
}
