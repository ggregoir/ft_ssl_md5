/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 19:44:00 by jafaghpo          #+#    #+#             */
/*   Updated: 2019/06/12 19:50:26 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

size_t		tab_size(char **tab)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (tab[i++])
		count++;
	return (count);
}
