/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 20:25:01 by ggregoir          #+#    #+#             */
/*   Updated: 2019/06/11 01:34:38 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"


void prompt_md5(char *to_hash __attribute__((unused)), int8_t *flags __attribute__((unused)))
{
	printf("je lis le promot super c'est du md5\n");
	exit(EXIT_SUCCESS);
}

void md5(char *to_hash, int8_t *flags __attribute__((unused)))
{
	printf("%s\n", to_hash);
	if (flags['s'])
	{
		printf("MD5(\"%s\") = steak hashé\n", to_hash);
	}
	else
	{
		printf("MD5(%s) = steak hashé\n", to_hash);
		printf("hahaha\n");
		if ((to_hash = get_file(to_hash)) != NULL)
			printf("to_hash: %s\n", to_hash);
	}
}