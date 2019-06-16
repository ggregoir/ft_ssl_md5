/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fopen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 18:58:02 by jafaghpo          #+#    #+#             */
/*   Updated: 2019/06/09 18:58:03 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"
#include <stdlib.h>
#include <fcntl.h>

t_file	*ft_fopen(char *filename, int mode)
{
	t_file	*file;

	if (!(file = malloc(sizeof(*file))))
		return (NULL);
	if ((file->fd = open(filename, mode)) == -1)
		return (NULL);
	file->len = 0;
	file->i = 0;
	return (file);
}
