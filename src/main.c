/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 12:31:33 by ggregoir          #+#    #+#             */
/*   Updated: 2019/05/21 14:01:56 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int		argv_len(char **argv, int argc)
{
	int i;
	int count;

	i = 0;
	count = 1;
	while (count != argc)
	{
		i += ft_strlen(argv[count]);
		count++;
	}
	return (i);
}

char	*argv_to_str(char **argv, int argc)
{
	int i;
	int count;
	char *ret;
	int x;
	
	i = argv_len(argv, argc);
	ret = ft_strnew(i + argc);
	count = 1;
	i = 0;
	x = 0;
	while (count != argc)
	{
		while (argv[count][x] != '\0')
		{
			ret[i] = argv[count][x];
			x++;
			i++;
		}
		count++;
		ret[i] = ' ';
		i++;
		x = 0;
	}
	ret[i] = '\0';
	return(ret);
}

int	get_command(char *command, t_flags *flags)
{
	if (flags->md5 == 0 && flags->sha256 == 0)
		if (!(ft_strequ(command, "md5")) && !(ft_strequ(command, "sha256")))
			return(0);
		else if (ft_strequ(command, "md5"))
			flags->md5 = 1;
		else
			flags->sha256 = 1;
}

int get_flags(t_flags *flags, char *line)
{
	int i;
	char command[255];
	int j;

	i = 0;
	j = 0;
	while(line[i] != '\0')
	{
		while(line[i] == " " || line[i] == "	")
			i++;
		while(line[i] != " " || line[i] != "	")
			command[j++] == command[i++];
		command[j] = '\0';
		if (!get_command(command, flags))
			return(0);
		j = 0;

	}
}

int	parse_ssl_line(t_flags *flags, char *line)
{

	static void		(*eval[4])() = {prompt_md5, hash_md5, prompt_256, hash_256};
	if (!(current = get_flags(flags, line)))
		return(0);
	eval[current - 1](flags);
}

int read_prompt_first(t_flags *flags)
{
	int	ret;
	int	fd;
	char *line;

	fd = 0;
	ft_putstr("ft_ssl> ");
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (ft_strequ(line, "q"))
			return(0);
		if (!parse_ssl_line(flags, line))
			ft_putendl("usage blablabla");
		ft_putstr("ft_ssl> ");

	}
}

//temporary
// int get_command(char * command)
// {

// }

int main(int argc, char **argv)
{
	t_flags flags = {0, 0, 0, 0, 0};
	if (argc < 1)
	{
		read_prompt_first(&flags);
	}
	else
		printf("[%s]\n", argv_to_str(argv, argc));
	return 0;
}