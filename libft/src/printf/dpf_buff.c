/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dpf_buff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 19:05:08 by jafaghpo          #+#    #+#             */
/*   Updated: 2019/06/09 19:05:08 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static char	g_buf[PF_BUFF_SIZE];
static int	g_fd = 0;
static int	g_i = 0;

void	dpf_init_buff(int in_fd)
{
	if (g_fd != 0 && g_fd != in_fd)
		dpf_putbuff();
	g_fd = in_fd;
	g_i = 0;
}

void	dpf_buff(char *str, int len)
{
	int	unused __attribute__((unused));

	if (g_i + len > PF_BUFF_SIZE)
	{
		unused = write(g_fd, g_buf, g_i);
		g_i = 0;
	}
	ft_memcpy(g_buf + g_i, str, len);
	g_i += len;
}

void	dpf_putbuff(void)
{
	int	unused __attribute__((unused));

	unused = write(g_fd, g_buf, g_i);
	g_i = 0;
}
