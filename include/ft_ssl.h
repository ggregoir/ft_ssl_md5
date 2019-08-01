/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 12:34:59 by ggregoir          #+#    #+#             */
/*   Updated: 2019/08/01 23:43:23 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include "../libft/include/libft.h"
# include <fcntl.h>

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
	uint32_t h0;
	uint32_t h1;
	uint32_t h2;
	uint32_t h3;
	uint32_t hh0;
	uint32_t hh1;
	uint32_t hh2;
	uint32_t hh3;
}				t_md5;

typedef struct	s_sha256
{
	uint32_t h0;
	uint32_t h1;
	uint32_t h2;
	uint32_t h3;
	uint32_t h4;
	uint32_t h5;
	uint32_t h6;
	uint32_t h7;
	uint32_t hh0;
	uint32_t hh1;
	uint32_t hh2;
	uint32_t hh3;
	uint32_t hh4;
	uint32_t hh5;
	uint32_t hh6;
	uint32_t hh7;
	uint32_t t1;
	uint32_t ch;
	uint32_t t0;
	uint32_t tmp1;
	uint32_t tmp2;
	uint32_t maj;
}				t_sha256;

typedef struct	s_line
{
	char			*tab;
	int				fd;
	struct s_line	*next;
}				t_line;

/*
** functions_str.c
*/
char			**split_spaces(char *line);
char			*ft_strjoin_and_free(char *s1, char *s2, char c, int at);
void			free_tab(char **tab);
/*
** get_next_line.c
*/
int				get_next_line(const int fd, char **line);
/*
** error.c
*/
void			print_usage_ssl(void);
int				ft_ssl_error(char *command);
void			illegal_option(char c);
int				flag_string_error(void);
/*
** main.c
*/
int				get_file(char *filename);
char			*read_fd(int fd);
void			md5(char *to_hash, int8_t *flags);
void			sha256(char *to_hash, int8_t *flags);
void			prompt_md5(char *to_hash, int8_t *flags);
void			prompt_sha256(char *to_hash, int8_t *flags);
char			**str_split_space(char const *s);
int				count_words(const char *str);
/*
** parsing.c
*/
int				parse_ssl_line(int8_t *flags, t_hash *hash, char **tab);
/*
** op.c
*/
uint32_t		rotate_right(uint32_t x, uint32_t c);
uint32_t		rotate_left(uint32_t x, uint32_t c);
uint32_t		swap_bytes_32bit(uint32_t val);
/*
** print_md5.c
*/
void			print_md5(char *to_hash);
void			md5_p(char *to_hash, int8_t *flags);
void			md5_q(char *to_hash, int8_t *flags);
void			md5_r(char *to_hash, int8_t *flags);
void			md5_noflag(char *to_hash, int8_t *flags);
/*
** tables.c
*/
void			init_hash_md5(t_md5 *hash);
void			init_hash_sha256(t_sha256 *hash);
/*
** print_sha256.c
*/
void			print_sha256(char *to_hash);
void			sha256_p(char *to_hash, int8_t *flags);
void			sha256_q(char *to_hash, int8_t *flags);
void			sha256_r(char *to_hash, int8_t *flags);
void			sha256_noflag(char *to_hash, int8_t *flags);
/*
** md5.c
*/
void			md5_algo(char *to_hash, int len, t_md5 *hash);
/*
** sha256.c
*/
void			sha256_algo(char *to_hash, uint32_t len, t_sha256 *hash);
void			add_padding(int len, uint32_t *msg);
void			add_size(uint32_t *msg, uint32_t bitlen, uint32_t newlen);
uint32_t		*init_msg(uint32_t *bitlen, uint32_t *newlen, uint32_t *len);

#endif
