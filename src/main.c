/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 12:31:33 by ggregoir          #+#    #+#             */
/*   Updated: 2019/06/11 01:59:37 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

size_t		tablen(char **tab)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (tab[i])
		count += ft_strlen(tab[i++]);
	return (count);
}

size_t		tabsize(char **tab)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (tab[i++])
		count++;
	return (count);
}

char		*implode(char **tab, char delim)
{
	char	*str;
	size_t	len;
	size_t	i;
	size_t	j;
	size_t	index;

	len = tablen(tab);
	if (!(str = (char*)malloc(len + tabsize(tab))))
		return (NULL);
	i = 0;
	index = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
			str[index++] = tab[i][j++];
		str[index++] = delim;
		i++;
	}
	str[index - 1] = 0;
	return (str);
}

char **split_spaces(char *line)
{
	char **tab;

	tab = ft_strsplit(line, '	');
	tab = ft_strsplit(implode(tab,' '), ' ');
	return(tab);
}

int	handle_flags(char *command, int8_t *flags)
{
	int i;

	i = 1;
	if (ft_strequ(command, "--"))
	{
		flags['-'] = 1;
		return (1);
	}
	else
	{
		while (command[i] != '\0')
		{
			if (flags[(uint8_t)command[i]] == -1)
				illegal_option(command[i]);
			else
				flags[(uint8_t)command[i]] = 1;
			i++;
		}
		return (1);
	}
	
}

void do_hash(char *to_hash, int8_t *flags, 	uint8_t current)
{
	static void	(*eval[4])(char *, int8_t *) = {md5, prompt_md5, sha256, prompt_sha256};
	printf("current: %d\n", current);
	eval[current - 1](to_hash, flags);
}

int		handle_hash(t_hash *hash, char *arg)
{
	if (!(ft_strequ(arg, "md5")) && !(ft_strequ(arg, "sha256")))
			return(ft_ssl_error(arg));
		else if (ft_strequ(arg, "md5"))
			hash->md5 = 1;
		else
		{
			printf("hello\n");
			hash->sha256 = 3;
		}
		return('s');
}

int	parse_ssl_line(int8_t *flags, t_hash *hash, char **tab)
{
	int i;

	i = 0;
	printf("tabsize: %zu\n", tabsize(tab));
	hash->prompt = 1;
	while(tab[i])
	{
		printf("tab; %s\n", tab[i]);
		if (!hash->md5 && !hash->sha256)
		{
			if (!handle_hash(hash, tab[i]))
				return(0);
			i++;
			continue;
		}
		else
		{
			printf("yo\n");
			if (flags['s'])
			{
				printf("popidou\n");
				do_hash(tab[i], flags, hash->md5 + hash->sha256);
				flags['s'] = 0;
				hash->prompt = 0;
				i++;
				continue;
			}
			if (!flags['-'] && tab[i][0] == '-')
			{
				if (!handle_flags(tab[i], flags))
					return(0);
				i++;
				continue;
			}
			else if (hash->md5 || hash->sha256)
			{
				printf("on enleve le prompt a : %s\n", tab[i]);
				hash->prompt = 0;
				printf("on enleve les flags a : %s\n", tab[i]);
				flags['-'] = 1;
			}
		}
		do_hash(tab[i], flags, hash->md5 + hash->sha256 + hash->prompt);
		i++;
	}
	if(hash->prompt == 1)
	{
		printf("boup boup pidoup\n");
		do_hash(tab[i], flags, hash->md5 + hash->sha256 + hash->prompt);
	}

	return (1);
}

void read_prompt_first(int8_t *flags, t_hash *hash)
{
	int	ret;
	int	fd;
	char *line;

	fd = 0;
	ft_putstr("ft_ssl> ");
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (ft_strequ(line, "q") || ft_strequ(line, "quit"))
			return;
		if (!parse_ssl_line(flags, hash, split_spaces(line)))
			print_usage_ssl();
		ft_putstr("ft_ssl> ");
	}
}

void test()
{
	char **tab;
	int i = 0;

	tab = ft_strsplit("     md5		Makefile -asbjas lol		lel", '	');
	tab = ft_strsplit(implode(tab,' '), ' ');
	while (tab[i])
		printf("%s\n", tab[i++]);
}

int main(int argc, char **argv)
{
	argv++;
	int i;
	int8_t flags[128];

	i = 0;
	t_hash hash = {0, 0, 0};
	ft_memset((void*)&flags, -1, 128);
	flags['p'] = 0;
	flags['q'] = 0;
	flags['r'] = 0;
	flags['s'] = 0;
	flags['-'] = 0;


	// ft_putstr("argc: ");
	// ft_putnbr(argc);
	// ft_putendl("");

	if (argc <= 1)
	{
		read_prompt_first(flags, &hash);
	}
	else if (!parse_ssl_line(flags, &hash, argv))
		print_usage_ssl();
	return 0;
}