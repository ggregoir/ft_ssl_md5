/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 20:40:44 by ggregoir          #+#    #+#             */
/*   Updated: 2019/11/27 23:15:41 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_link	*list_insert(t_list *list, t_link *new, t_uint64 index)
{
	t_link	*current;

	if (index > list->length)
		return (NULL);
	else if (index == 0)
		list_push_first(list, new);
	else if (index == list->length)
		list_push_last(list, new);
	else
	{
		current = list_get(list, index);
		new->prev = current->prev;
		new->next = current;
		current->prev->next = new;
		current->prev = new;
	}
	list->length++;
	return (new);
}
