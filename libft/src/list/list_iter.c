/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_iter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 20:40:52 by ggregoir          #+#    #+#             */
/*   Updated: 2019/11/27 23:15:41 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	list_iter(t_list *list, void (*f)(t_link *))
{
	t_link	*iter;

	iter = list->first;
	while (iter)
	{
		(*f)(iter);
		iter = iter->next;
	}
}
