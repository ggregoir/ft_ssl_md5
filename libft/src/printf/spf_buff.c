/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spf_buff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 19:06:03 by ggregoir          #+#    #+#             */
/*   Updated: 2019/11/27 23:15:02 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static char	*g_buf;
static int	g_i;

void	spf_init_buff(char *str)
{
	g_i = 0;
	g_buf = str;
}

void	spf_buff(char *str, int len)
{
	ft_memcpy(g_buf + g_i, str, len);
	g_i += len;
}
