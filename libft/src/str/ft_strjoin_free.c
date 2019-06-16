/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 19:00:07 by jafaghpo          #+#    #+#             */
/*   Updated: 2019/06/09 19:00:08 by jafaghpo         ###   ########.fr       */
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
