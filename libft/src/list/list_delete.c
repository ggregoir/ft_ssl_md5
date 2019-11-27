/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_delete.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 20:39:39 by ggregoir          #+#    #+#             */
/*   Updated: 2019/11/27 23:15:40 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	link_delete(t_link **link)
{
	free((*link)->data);
	(*link)->data = NULL;
	(*link)->size = 0;
	free(*link);
	*link = NULL;
}

void	list_delete(t_list **list)
{
	t_link	*tmp;
	t_link	*iter;

	iter = (*list)->first;
	while (iter)
	{
		tmp = iter->next;
		link_delete(&iter);
		iter = tmp;
	}
	(*list)->length = 0;
	free(*list);
	*list = NULL;
}
