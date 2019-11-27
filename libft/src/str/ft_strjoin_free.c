/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 19:00:07 by ggregoir          #+#    #+#             */
/*   Updated: 2019/11/27 23:39:32 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"
#include <stdlib.h>

char	*ft_strjoin_free(char *s1, char *s2, unsigned short int c)
{
	char	*tmp;

	tmp = ft_strjoin(s1, s2);
	if (c == 'L' || c == 'L' + 'R')
		free(s1);
	if (c == 'R' || c == 'L' + 'R')
		free(s2);
	return (tmp);
}
