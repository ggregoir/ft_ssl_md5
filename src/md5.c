/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 20:25:01 by ggregoir          #+#    #+#             */
/*   Updated: 2019/06/06 00:07:01 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"


void *prompt_md5(t_hash *hash, int8_t *flags)
{
	return(md5(read_fd(0), flags));
}

void *md5(t_hash *hash, int8_t *flags)
{
	while(hash->queue->data)
	{
		if (hash->queue->data[0] == -1)
		{
			printf("MD5(\"%s\"\n", hash->queue->data + 1);
		}
		else
		{
			printf("MD5(%s) = \n", hash->queue->data);
		}
			hash->queue->data = hash->queue->next;
	}
	return(str);
}