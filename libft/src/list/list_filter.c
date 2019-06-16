/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_filter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 20:39:48 by jafaghpo          #+#    #+#             */
/*   Updated: 2019/06/11 19:34:47 by jafaghpo         ###   ########.fr       */
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
