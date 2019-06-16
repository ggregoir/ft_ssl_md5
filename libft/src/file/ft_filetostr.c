/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filetostr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 18:58:00 by jafaghpo          #+#    #+#             */
/*   Updated: 2019/06/09 18:58:00 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"
#include "str.h"
#include "put.h"
#include <unistd.h>
#include <fcntl.h>

char	*ft_filetostr(char *file)
{
	int		fd;
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*str;

	str = NULL;
	if ((fd = open(file, O_RDONLY)) == -1)
		ft_error("error open in ft_filetostr");
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret == -1)
			ft_error("error read in ft_filetostr");
		buf[ret] = '\0';
		str = ft_strjoin_free(str, buf, 'L');
	}
	if (close(fd) == -1)
		ft_error("error close in ft_filetostr");
	return (str);
}
