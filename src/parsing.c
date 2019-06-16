/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 15:27:11 by ggregoir          #+#    #+#             */
/*   Updated: 2019/06/16 19:29:29 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

char *get_file(char *filename)
{
	int fd;
	
	if((fd = open(filename, O_RDONLY)) == -1)
	{
		ft_dprintf(2, "%s: No such file or directory\n", filename);
		return(NULL);
	}
	return(read_fd(fd));
}

char *read_fd(int fd)
{
	char buff[100001];
	int count;
	char *ret;

	count = 0;
	ret = NULL;

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
		if ((ret = ft_strjoin_free(ret, buff, 'L')) == NULL)
			return(NULL);
	}
	return(NULL);
}