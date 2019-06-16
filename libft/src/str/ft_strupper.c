/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 19:01:53 by jafaghpo          #+#    #+#             */
/*   Updated: 2019/06/09 19:01:53 by jafaghpo         ###   ########.fr       */
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
