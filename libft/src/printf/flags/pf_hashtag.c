/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_hashtag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 19:04:42 by jafaghpo          #+#    #+#             */
/*   Updated: 2019/06/09 19:04:43 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pf_hashtag(char *format, va_list arg, t_pfflags *flags)
{
	(void)arg;
	flags->tags.hashtag = 1;
	return (format + 1);
}
