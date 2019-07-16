/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 12:31:33 by ggregoir          #+#    #+#             */
/*   Updated: 2019/07/12 03:02:03 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

char *get_file(char *filename)
{
	int fd;
	
	if((fd = open(filename, O_RDONLY)) == -1)
	{
		ft_dprintf(2, "%s: No such file or directory\n", filename);
		return(NULL);
	}
	return(read_fd(fd));
}

char *read_fd(int fd)
{
	char buff[100001];
	int count;
	char *ret;

	count = 0;
	ret = NULL;

	while ((count = read(fd, buff, 100000)) >= 0)
	{
		if (count == 0)
			return(ret);
		buff[count] = '\0';
		if (!ret)
		{
			if (!(ret = ft_strnew(count)))
				return(NULL);
		}
		if ((ret = ft_strjoin_free(ret, buff, 'L')) == NULL)
			return(NULL);
	}
	return(NULL);
}

int		parse_ssl_line(int8_t *flags, t_hash *hash, char **tab)
{
	int i;

	i = -1;
	hash->prompt = 1;
	while(tab[++i])
	{
		if (!hash->md5 && !hash->sha256)
		{
			if (!handle_hash(hash, tab[i]))
				return(0);
		}
		else
		{
			if (!handle_args(flags, hash, &i, tab))
				return(0);
		}
	}
	if (flags['s'])
		return(flag_string_error());
	if(hash->prompt == 1)
		do_hash(tab[i], flags, hash->md5 + hash->sha256 + hash->prompt);
	return (1);
}

void read_prompt_first(int8_t *flags, t_hash *hash)
{
	int	ret;
	int	fd;
	char *line;

	fd = 0;
	ft_printf("ft_ssl> ");
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (ft_strequ(line, "q") || ft_strequ(line, "quit"))
			return;
		if (!parse_ssl_line(flags, hash, split_spaces(line)))
			print_usage_ssl();
		ft_bzero(hash, sizeof(hash));
		flags['p'] = 0;
		flags['q'] = 0;
		flags['r'] = 0;
		flags['s'] = 0;
		flags['-'] = 0;
		ft_printf("ft_ssl> ");
	}
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
	if (argc <= 1)
	{
		read_prompt_first(flags, &hash);
	}
	else if (!parse_ssl_line(flags, &hash, argv))
		print_usage_ssl();
	return 0;
}