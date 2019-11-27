/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 19:01:53 by ggregoir          #+#    #+#             */
/*   Updated: 2019/11/27 23:13:55 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"
#include "char.h"

char	*ft_strupper(char *str)
{
	char	*ret;

	ret = str;
	while (*str)
	{
		if (ft_islower(*str))
			*str -= 32;
		str++;
	}
	return (ret);
}
