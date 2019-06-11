/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 23:14:36 by ggregoir          #+#    #+#             */
/*   Updated: 2019/06/11 01:52:01 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"


void prompt_sha256(char *to_hash __attribute__((unused)), int8_t *flags __attribute__((unused)))
{
	printf("je lis le promot super c'est du sha256\n");
	exit(EXIT_SUCCESS);
}

void sha256(char *to_hash, int8_t *flags __attribute__((unused)))
{
	printf("%s\n", to_hash);
	if (flags['s'])
	{
		printf("sha256(\"%s\") = steak hashé\n", to_hash);
	}
	else
	{
		printf("sha256(%s) = steak hashé\n", to_hash);

		if ((to_hash = get_file(to_hash)) != NULL)
			printf("to_hash: %s\n", to_hash);
	}
}