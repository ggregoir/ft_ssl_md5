/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 20:41:25 by jafaghpo          #+#    #+#             */
/*   Updated: 2019/06/11 19:59:49 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	list_push_first(t_list *list, t_link *new)
{
	if (!list->first)
	{
		list->first = new;
		list->last = new;
		new->prev = NULL;
		new->next = NULL;
	}
	else
	{
		new->next = list->first;
		list->first->prev = new;
		list->first = new;
		new->prev = NULL;
	}
	list->length += 1;
}

void	list_push_last(t_list *list, t_link *new)
{
	if (!list->last)
	{
		list->first = new;
		list->last = new;
		new->prev = NULL;
		new->next = NULL;
	}
	else
	{
		new->prev = list->last;
		list->last->next = new;
		list->last = new;
		new->next = NULL;
	}
	list->length += 1;
}
