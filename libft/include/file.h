/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 18:55:02 by jafaghpo          #+#    #+#             */
/*   Updated: 2019/06/09 18:55:02 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H

# define BUFF_SIZE 65535

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

typedef struct s_gnl	t_gnl;
typedef struct s_file	t_file;

struct	s_file
{
	int		fd;
	char	buf[BUFF_SIZE];
	int		len;
	int		i;
};

struct	s_gnl
{
	char	*tmp;
	char	buf[BUFF_SIZE + 1];
};

char	*ft_filetostr(char *file);
int		get_next_line(const int fd, char **line);
t_file	*ft_fopen(char *filename, int mode);
int		ft_getline(char **line, t_file *file);

#endif
