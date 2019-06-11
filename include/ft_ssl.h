/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 12:34:59 by ggregoir          #+#    #+#             */
/*   Updated: 2019/06/11 01:34:08 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NPUZZLE_H
# define NPUZZLE_H

# include "../libft/includes/libft.h"

//delete me 
# include <stdio.h>

# define MAX_FILE_SIZE 209715200

# define TRUE 1
# define FALSE 0

typedef struct	s_hash
{
	uint8_t	md5;
	uint8_t	sha256;
	uint8_t	prompt;
}				t_hash;

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
int		ft_ssl_error(char *command);
void	illegal_option(char c);
char	*argv_to_str(char **argv, int argc);
char	*get_file(char *filename);
char 	*read_fd(int fd);
void	md5(char *to_hash, int8_t *flags);
void	sha256(char *to_hash, int8_t *flags);
void	prompt_md5(char *to_hash, int8_t *flags);
void	prompt_sha256(char *to_hash, int8_t *flags);
char			**str_split_space(char const *s);
int		count_words(const char *str);

#endif