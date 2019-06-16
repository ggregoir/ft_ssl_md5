/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_remove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 20:41:32 by jafaghpo          #+#    #+#             */
/*   Updated: 2019/06/11 00:41:10 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_link	*link_remove(t_link *link)
{
	t_link	*prev;
	t_link	*next;

	prev = link->prev;
	next = link->next;
	prev->next = next;
	next->prev = prev;
	link->prev = NULL;
	link->next = NULL;
	return (link);
}

t_link	*list_remove(t_list *list, t_uint64 index)
{
	t_link	*link;

	if (index == 0)
		link = list_pop_first(list);
	else if (index == list->length - 1)
		link = list_pop_last(list);
	else
		link = list_get(list, index);
	if (link == NULL)
		return (NULL);
	link = link_remove(link);
	return (link);
}
