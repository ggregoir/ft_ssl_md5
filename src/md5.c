/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 20:25:01 by ggregoir          #+#    #+#             */
/*   Updated: 2019/06/05 00:11:28 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"


char *prompt_md5(int8_t *flags)
{
	return(md5(read_fd(0), flags));
}

char *md5(char *str, int8_t *flags)
{
	flags['t'] = -1;
	return(str);
}