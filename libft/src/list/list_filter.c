/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_filter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 20:39:48 by ggregoir          #+#    #+#             */
/*   Updated: 2019/11/27 23:15:40 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list	*list_filter(t_list *list, bool (*f)(t_link *))
{
	t_list	*new_list;
	t_link	*iter;
	t_link	*new_link;

	new_list = list_new(NULL, 0);
	iter = list->first;
	while (iter)
	{
		if (f(iter))
		{
			new_link = link_new(iter->data, iter->size);
			if (new_link == NULL)
				return (NULL);
			list_push_last(new_list, new_link);
		}
		iter = iter->next;
	}
	return (new_list);
}
