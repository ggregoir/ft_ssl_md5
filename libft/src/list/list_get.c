/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 20:40:17 by jafaghpo          #+#    #+#             */
/*   Updated: 2019/06/11 00:37:25 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "ft_printf.h"

t_link	*list_get_from_first(t_link *first, t_uint64 offset)
{
	while (offset)
	{
		if (first == NULL)
			return (NULL);
		first = first->next;
		offset--;
	}
	return (first);
}

t_link	*list_get_from_last(t_link *last, t_uint64 offset)
{
	while (offset)
	{
		if (last == NULL)
			return (NULL);
		last = last->prev;
		offset--;
	}
	return (last);
}

t_link	*list_get(t_list *list, t_uint64 index)
{
	if (index >= list->length)
		return (NULL);
	if (index < list->length / 2)
		return (list_get_from_first(list->first, index));
	else
		return (list_get_from_last(list->last, list->length - index - 1));
}
