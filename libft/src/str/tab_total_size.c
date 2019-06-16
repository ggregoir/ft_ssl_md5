/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_total_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 19:33:56 by jafaghpo          #+#    #+#             */
/*   Updated: 2019/06/12 19:49:54 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

size_t		tab_total_size(char **tab)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (tab[i])
		count += ft_strlen(tab[i++]);
	return (count);
}
