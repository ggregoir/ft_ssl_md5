/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 12:31:33 by ggregoir          #+#    #+#             */
/*   Updated: 2019/11/27 23:36:27 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int		get_file(char *filename)
{
	int fd;

	if ((fd = open(filename, O_RDONLY)) == -1)
	{
		ft_dprintf(2, "%s: No such file or directory\n", filename);
		return (-1);
	}
	return (fd);
}

char	*read_fd(int fd, size_t *len)
{
	char	buff[100001];
	char	*ret;
	int		count;

	*len = 0;
	ret = NULL;
	while ((count = read(fd, buff, 100000)) >= 0)
	{
		*len += count;
		if (count == 0)
		{
			return (ret);
		}
		buff[count] = '\0';
		if (!ret)
		{
			if (!(ret = ft_strnew(count)))
				return (NULL);
		}
		ret = ft_realloc(ret, *len);
		ft_strncpy(ret + *len - count, buff, count);
	}
	return (NULL);
}

void	read_prompt_first(int8_t *flags, t_hash *hash)
{
	int		ret;
	int		fd;
	char	*line;
	char	**tab;

	fd = 0;
	ft_printf("ft_ssl> ");
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (ft_strequ(line, "q") || ft_strequ(line, "quit"))
			return ;
		tab = split_spaces(line);
		if (!parse_ssl_line(flags, hash, tab))
			print_usage_ssl();
		ft_bzero(hash, sizeof(hash));
		flags['p'] = 0;
		flags['q'] = 0;
		flags['r'] = 0;
		flags['s'] = 0;
		flags['-'] = 0;
		free_tab(tab);
		free(line);
		ft_printf("ft_ssl> ");
	}
}

int		main(int argc, char **argv)
{
	int		i;
	int8_t	flags[128];
	t_hash	hash;

	ft_memset(&hash, 0, sizeof(t_hash));
	argv++;
	i = 0;
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
	return (0);
}
