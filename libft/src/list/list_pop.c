/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_pop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 20:41:20 by jafaghpo          #+#    #+#             */
/*   Updated: 2019/06/11 00:28:04 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_link	*list_pop_first(t_list *list)
{
	t_link	*first;

	if (!list->first)
		return (NULL);
	else
	{
		first = list->first;
		list->first = first->next;
		list->first->prev = NULL;
		list->length -= 1;
		return (first);
	}
}

t_link	*list_pop_last(t_list *list)
{
	t_link	*last;

	if (!list->last)
		return (NULL);
	else
	{
		last = list->last;
		list->last = last->prev;
		list->last->next = NULL;
		list->length -= 1;
		return (last);
	}
}
