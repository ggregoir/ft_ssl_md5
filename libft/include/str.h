/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 18:56:57 by jafaghpo          #+#    #+#             */
/*   Updated: 2019/06/12 19:52:20 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_H
# define STR_H

# include <wchar.h>
# include <unistd.h>

void	ft_delspace(char **str);
int		ft_strcmp_space(char *s1, char *s2);
char	*ft_strmap(const char *s, char (*f)(char));
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));
int		ft_strequ(const char *s1, const char *s2);
int		ft_strnequ(const char *s1, const char *s2, size_t n);
char	*ft_strsub(const char *s, unsigned int start, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strjoin_free(char *s1, char *s2, unsigned short int c);
char	*ft_strtrim(const char *s);
char	**ft_strsplit(const char *s, char c);
size_t	ft_strlen(const char *str);
size_t	ft_wstrlen(wchar_t *str);
char	*ft_strdup(const char *str);
char	*ft_strcpy(char *dest, const char *src);
wchar_t	*ft_wstrcpy(wchar_t *dest, const wchar_t *src);
char	*ft_strncpy(char *dest, const char *src, size_t n);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strncat(char *dest, const char *src, size_t n);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
char	*ft_strstr(const char *s1, const char *s2);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnew(size_t size);
void	ft_strdel(char **as);
void	ft_strdel(char **as);
void	ft_strclr(char *s);
void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
int		ft_countstr(char *str);
size_t	tab_total_size(char **tab);
size_t	tab_size(char **tab);
char	*implode(char **tab, char delim);

#endif
