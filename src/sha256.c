/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 23:14:36 by ggregoir          #+#    #+#             */
/*   Updated: 2019/06/06 20:53:07 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"


void prompt_sha256(t_hash *hash __attribute__((unused)), int8_t *flags __attribute__((unused)))
{

}

void sha256(t_hash *hash, int8_t *flags __attribute__((unused)))
{
	while(hash->queue->data)
	{
		if (((char *) hash->queue->data)[0] == -1)
		{
			printf("SHA256(\"%s\"\n", hash->queue->data + 1);
		}
		else
		{
			printf("SHA256(%s) = \n", hash->queue->data);
		}
			hash->queue = hash->queue->next;
	}
}