/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 20:41:06 by jafaghpo          #+#    #+#             */
/*   Updated: 2019/06/11 19:51:36 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "mem.h"

t_link	*link_new(void *data, t_uint64 size)
{
	t_link	*new;
	void	*new_data;

	if (!(new = (t_link *)malloc(sizeof(*new))))
		return (NULL);
	if (data == NULL)
	{
		new->size = 0;
		new->data = NULL;
	}
	else
	{
		if (!(new_data = ft_memdup(data, size)))
			return (NULL);
		new->size = size;
		new->data = new_data;
	}
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_list	*list_new(void *data, t_uint64 size)
{
	t_list	*new_list;
	t_link	*new_link;

	if (!(new_list = (t_list *)malloc(sizeof(*new_list))))
		return (NULL);
	if (data == NULL)
	{
		new_list->first = NULL;
		new_list->last = NULL;
		new_list->length = 0;
	}
	else
	{
		if (!(new_link = link_new(data, size)))
		{
			free(new_list);
			return (NULL);
		}
		new_list->first = new_link;
		new_list->last = new_link;
		new_list->length = 1;
	}
	return (new_list);
}
