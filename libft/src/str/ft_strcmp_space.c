/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_space.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 18:59:42 by jafaghpo          #+#    #+#             */
/*   Updated: 2019/06/09 18:59:42 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

int		ft_strcmp_space(char *s1, char *s2)
{
	ft_delspace(&s1);
	ft_delspace(&s2);
	while (*s1 == *s2 && *s1 != ' ' && *s1 != '\t' && *s1)
	{
		s1++;
		s2++;
	}
	ft_delspace(&s1);
	ft_delspace(&s2);
	return (!s1 && !s2);
}
