/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 23:14:36 by ggregoir          #+#    #+#             */
/*   Updated: 2019/06/12 00:08:11 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"


void		prompt_sha256(char *to_hash __attribute__((unused)), int8_t *flags __attribute__((unused)))
{
	to_hash = read_fd(0);
	printf("\nje dois hash:%s\n", to_hash);
	exit(EXIT_SUCCESS);
}

void		sha256(char *to_hash, int8_t *flags __attribute__((unused)))
{
	char *filename;

	if (flags['s'])
	{
		printf("SHA256(\"%s\") = steak hashé\n", to_hash);
	}
	else
	{
	filename = to_hash;
	if ((to_hash = get_file(to_hash)) != NULL)
			printf("SHA256(%s) = %s\n", filename, to_hash);
	}
}