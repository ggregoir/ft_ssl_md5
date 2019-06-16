/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_iter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 20:40:52 by jafaghpo          #+#    #+#             */
/*   Updated: 2019/06/10 20:40:53 by jafaghpo         ###   ########.fr       */
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
