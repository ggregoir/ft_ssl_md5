/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 18:59:23 by ggregoir          #+#    #+#             */
/*   Updated: 2019/11/27 23:15:11 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "put.h"
#include "str.h"
#include <unistd.h>
#include <stdlib.h>

void	ft_error(char *str)
{
	int	unused __attribute__((unused));

	unused = write(2, str, ft_strlen(str));
	exit(EXIT_FAILURE);
}
