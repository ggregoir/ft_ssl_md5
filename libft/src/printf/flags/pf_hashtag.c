/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_hashtag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 19:04:42 by ggregoir          #+#    #+#             */
/*   Updated: 2019/11/27 23:14:50 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pf_hashtag(char *format, va_list arg, t_pfflags *flags)
{
	(void)arg;
	flags->tags.hashtag = 1;
	return (format + 1);
}
