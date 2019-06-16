/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 19:16:36 by jafaghpo          #+#    #+#             */
/*   Updated: 2019/06/11 23:41:39 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_link(t_link *link)
{
	ft_printf("\"%s\"\n", (char*)(link->data));
}

bool	size_lt_12(t_link *link)
{
	return (link->size < 12);
}

void	test_list()
{
	t_list	*list __attribute__((cleanup(list_delete)));
	t_list	*filtered_list __attribute__((cleanup(list_delete)));
	t_list	*removed_list __attribute__((cleanup(list_delete)));
	t_link	*tmp;

	list = list_new(NULL, 0);
	removed_list = list_new(NULL, 0);

	ft_printf("Adding elem to list:\n");
	list_push_last(list, link_new("push last 1", 11));
	list_push_first(list, link_new("push first 1", 12));
	list_push_first(list, link_new("push first 2", 12));
	list_push_first(list, link_new("push first 3", 12));
	list_push_last(list, link_new("push last 2", 11));
	list_insert(list, link_new("insert at index 1", 17), 1);
	list_push_last(list, link_new("push last 3", 11));
	list_iter(list, print_link);

	ft_printf("\nLength of list: %d\n", list->length);

	ft_printf("\nGetting elem at index:\n");
	print_link(list_get(list, 3));

	ft_printf("\nFilter elem with a size lower than 12:\n");
	filtered_list = list_filter(list, size_lt_12);
	list_iter(filtered_list, print_link);

	ft_printf("\nPop first elem: ");
	tmp = list_pop_first(list);
	print_link(tmp);
	list_push_first(removed_list, tmp);
	list_iter(removed_list, print_link);

	ft_printf("\nPop last elem: ");
	tmp = list_pop_last(list);
	print_link(tmp);
	list_push_first(removed_list, tmp);
	list_iter(removed_list, print_link);

	ft_printf("\nRemove elem at index 2: ");
	tmp = list_remove(list, 2);
	print_link(tmp);
	list_push_first(removed_list, tmp);
	list_iter(removed_list, print_link);
}

void	test_vec()
{
	t_vec	vec;

	vec = vec_new("a new vector", 12);
	ft_printf("data: %s\nsize: %d\ncapacity power: %d\ntotal capacity: %d\n",
		vec.data, vec.size, vec.capacity, 1 << vec.capacity);
}

int		main(int ac, char **av)
{
	// test_list();
	test_vec();
	return (0);
}