/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 12:34:59 by ggregoir          #+#    #+#             */
/*   Updated: 2019/05/22 17:40:10 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NPUZZLE_H
# define NPUZZLE_H

# include "../libft/includes/libft.h"
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <ctype.h>

# define MAX_FILE_SIZE 209715200

# define TRUE 1
# define FALSE 0

typedef struct	s_flags
{
	uint8_t	reverse;
	uint8_t	silent;
	uint8_t	md5;
	uint8_t	sha256;
	uint8_t	noflags;
	char	filename[255];
	char	*content;
	
}				t_flags;


typedef struct	s_line
{
	char			*tab;
	int				fd;
	struct s_line	*next;
}				t_line;



int		match_str(char *str, char *to_match);
char	*ft_strjoin_and_free(char *s1, char *s2, char c, int at);
int		get_next_line(const int fd, char **line);
void	print_usage();
void	print_usage_ssl();
void	ft_ssl_error(char *command);
char	*argv_to_str(char **argv, int argc);

#endif