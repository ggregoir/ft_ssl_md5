/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 12:34:59 by ggregoir          #+#    #+#             */
/*   Updated: 2019/07/09 23:22:48 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NPUZZLE_H
# define NPUZZLE_H

# include "../libft/include/libft.h"
#include <fcntl.h>

# define MAX_FILE_SIZE 209715200

# define TRUE 1
# define FALSE 0

const uint32_t	g_sine[64];
const uint32_t	g_shifts[64];
const uint32_t	g_round[64];

typedef struct	s_hash
{
	uint8_t	md5;
	uint8_t	sha256;
	uint8_t	prompt;
}				t_hash;

typedef struct	s_md5
{
	unsigned int h0;
	unsigned int h1;
	unsigned int h2;
	unsigned int h3;
	unsigned int hh0;
	unsigned int hh1;
	unsigned int hh2;
	unsigned int hh3;
}				t_md5;

typedef struct	s_sha256
{
	unsigned int h0;
	unsigned int h1;
	unsigned int h2;
	unsigned int h3;
	unsigned int h4;
	unsigned int h5;
	unsigned int h6;
	unsigned int h7;
	unsigned int hh0;
	unsigned int hh1;
	unsigned int hh2;
	unsigned int hh3;
	unsigned int hh4;
	unsigned int hh5;
	unsigned int hh6;
	unsigned int hh7;
	unsigned int t1;
	unsigned int ch;
	unsigned int t0;
	unsigned int tmp1;
	unsigned int tmp2;
	unsigned int maj;
}				t_sha256;

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
char	**str_split_space(char const *s);
int		count_words(const char *str);
int		flag_string_error();

#endif