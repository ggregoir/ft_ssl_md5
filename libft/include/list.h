/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 20:38:49 by jafaghpo          #+#    #+#             */
/*   Updated: 2019/06/10 20:39:05 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <stdlib.h>
# include <stdbool.h>
# include "type.h"

typedef struct s_link	t_link;
typedef struct s_list	t_list;

struct	s_list
{
	t_link		*first;
	t_link		*last;
	t_uint64	length;
};

struct	s_link
{
	void		*data;
	t_uint64	size;
	t_link		*next;
	t_link		*prev;
};

t_list	*list_new(void *data, t_uint64 size);
t_link	*link_new(void *data, t_uint64 size);
void	list_delete(t_list **list);
void	link_delete(t_link **link);
t_link	*list_remove(t_list *list, t_uint64 index);
t_link	*link_remove(t_link *link);
void	list_push_first(t_list *list, t_link *new);
void	list_push_last(t_list *list, t_link *new);
t_link	*list_pop_first(t_list *list);
t_link	*list_pop_last(t_list *list);
void	list_iter(t_list *list, void (*f)(t_link *));
t_list	*list_map(t_list *list, t_link *(*f)(t_link *));
t_list	*list_filter(t_list *list, bool (*f)(t_link *));
t_link	*list_get(t_list *list, t_uint64 index);
t_link	*list_insert(t_list *list, t_link *new, t_uint64 index);

#endif
