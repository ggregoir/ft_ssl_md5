/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 20:25:01 by ggregoir          #+#    #+#             */
/*   Updated: 2019/06/06 22:45:09 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"


void prompt_md5(t_hash *hash __attribute__((unused)), int8_t *flags __attribute__((unused)))
{
	
}

void md5(t_hash *hash, int8_t *flags __attribute__((unused)))
{
	while(hash->queue->next)
	{
		if (hash->queue->data == NULL)
			return;
		if (((char *) hash->queue->data)[0] == -1)
		{
			printf("MD5(\"%s\") = steak hashé\n", hash->queue->data + 1);
		}
		else
		{
			printf("MD5(%s) = steak hashé\n", hash->queue->data);
		}
			hash->queue = hash->queue->next;
	}
}