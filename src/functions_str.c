/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:01:45 by ggregoir          #+#    #+#             */
/*   Updated: 2019/06/05 23:08:18 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static int		argv_len(char **argv, int argc)
{
	int i;
	int count;

	i = 0;
	count = 1;
	while (count != argc)
	{
		i += ft_strlen(argv[count]);
		count++;
	}
	return (i);
}

char	*argv_to_str(char **argv, int argc)
{
	int i;
	int count;
	char *ret;
	int x;
	
	i = argv_len(argv, argc);
	ret = ft_strnew(i + argc);
	count = 1;
	i = 0;
	x = 0;
	while (count != argc)
	{
		while (argv[count][x] != '\0')
		{
			ret[i] = argv[count][x];
			x++;
			i++;
		}
		count++;
		ret[i] = ' ';
		i++;
		x = 0;
	}
	ret[i] = '\0';
	return(ret);
}

int				match_str(char *str, char *to_match)
{
	int i;

	i = 0;
	while (str[i] == to_match[i])
	{
		if (str[i] == 0 && to_match[i] == 0 && i > 0)
			return(1);
		if (str[i] == 0 && to_match[i] == 0)
			break;
		i++;
	}
	return(0);
}

static size_t	ft_strlenchr(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char			*ft_strjoin_and_free(char *s1, char *s2, char c, int at)
{
	size_t	i;
	size_t	j;
	char	*ret;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlenchr(s2, c);
	if (!(ret = (char *)malloc(sizeof(char) * (i + j + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		ret[j++] = s1[i++];
	i = 0;
	while (s2[i] && s2[i] != c)
		ret[j++] = s2[i++];
	ret[j] = '\0';
	if (at == 1 || at == 3)
		ft_strdel(&s1);
	if (at == 2 || at == 3)
		ft_strdel(&s2);
	return (ret);
}