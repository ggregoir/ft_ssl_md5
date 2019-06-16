/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 18:56:52 by jafaghpo          #+#    #+#             */
/*   Updated: 2019/06/11 19:45:02 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEM_H
# define MEM_H

# include <string.h>

void	*ft_realloc(void *data, size_t size);
int		ft_nbbits(unsigned long long int nb);
void	ft_memset(void *str, int c, size_t n);
void	ft_bzero(void *str, size_t n);
void	ft_memcpy(void *dest, void *src, int n);
void	*ft_memccpy(void *dest, const void *src, int c, size_t n);
void	*ft_memmove(void *dest, void *src, size_t n);
void	*ft_memchr(const void *str, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memalloc(size_t size);
void	ft_memdel(void **ap);
void	*ft_memdup(void *src, size_t n);

#endif
