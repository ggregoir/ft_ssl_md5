/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 18:59:23 by jafaghpo          #+#    #+#             */
/*   Updated: 2019/06/09 18:59:23 by jafaghpo         ###   ########.fr       */
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
