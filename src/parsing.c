/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 15:27:11 by ggregoir          #+#    #+#             */
/*   Updated: 2019/05/31 19:00:00 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

char *get_file(char *filename)
{
	char buff[100001];
	int fd;
	int count;
	char *ret;

	count = 0;
	ret = NULL;
	fd = open(filename, O_RDONLY);
	
	while ((count = read(fd, buff, 100000)) >= 0)
	{
		if (count == 0)
			return(ret);
		buff[count] = '\0';
		if (!ret)
		{
			if (!(ret = ft_strnew(count)))
				return(NULL);
		}
		if ((ret = ft_strjoinf(ret, buff, 1)) == NULL)
			return(NULL);
	}
	return(NULL);
}