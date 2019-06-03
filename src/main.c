/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 12:31:33 by ggregoir          #+#    #+#             */
/*   Updated: 2019/05/31 19:03:52 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void printlst(t_list *elem)
{
	ft_putstr("list elem: ");
	ft_putendl(elem->data);
}

int	handle_filename(char *command, t_flags *flags)
{
	ft_putstr("filename len: ");
	ft_putnbr(ft_strlen(command));
	ft_putendl("");
	ft_lst_add_back(&flags->filename, ft_lstnew(command, ft_strlen(command) + 1));
	return(1);
}

int	handle_flags(char *command, t_flags *flags)
{
	int i;

	i = 1;
	if (ft_strequ(command, "--"))
	{
		flags->noflags = 1;
		return(1);
	}
	else
	{
		while(command[i] != '\0')
		{
			if (command[i] != 'p' && command[i] != 'q' && command[i] != 'r' &&
				command[i] != 's')
			{
				illegal_option(command[i]);
				return(0);
			}
			if (command[i] == 'p')
				flags->prompt = 1;
			if (command[i] == 'q')
				flags->quiet = 1;
			if (command[i] == 'r')
				flags->reverse = 1;
			if (command[i] == 's')
				flags->string = 1;
			i++;
		}
		return(1);
	}
	
}

int	get_command(char *command, t_flags *flags)
{
	ft_putstr("command from get_command: ");
	ft_putendl(command);
	if (flags->md5 == 0 && flags->sha256 == 0)
		if (!(ft_strequ(command, "md5")) && !(ft_strequ(command, "sha256")))
		{
			ft_ssl_error(command);
			return(0);
		}
		else if (ft_strequ(command, "md5"))
			flags->md5 = 1;
		else
			flags->sha256 = 1;
	else
	{
		if (!flags->noflags && command[0] == '-')
		{
			if (!handle_flags(command, flags))
				return(0);
		}
		else
			handle_filename(command, flags);

	}
	return(1);
}

int get_flags(t_flags *flags, char *line)
{
	int i;
	char command[255];
	int j;

	// ft_putstr("line from get_flags: ");
	// ft_putendl(line);

	i = 0;
	j = 0;
	while(line[i] != '\0')
	{
		//printf("line[%d]: %c\n", i, line[i]);
		while(line[i] == ' ' || line[i] == '	')
		{
			//printf("line[%d]: %c\n", i, line[i]);
			i++;
		}
		while(line[i] != ' ' && line[i] != '	' && line[i] != '\0')
		{
			//printf("line[%d]: %c\n", i, line[i]);
			command[j++] = line[i++];
			//printf("command[j: %d]: %c\n", j, command[j]);
		}
		command[j] = '\0';
		// ft_putstr("command: ");
		// ft_putendl(command);
		if (!get_command(command, flags))
			return(0);
		j = 0;
	}
	return (1);
}

int	parse_ssl_line(t_flags *flags, char *line)
{
	uint8_t current;
	// ft_putstr("line from parse_line: ");
	// ft_putendl(line);
	//static void	(*eval[4])() = {prompt_md5, hash_md5, prompt_256, hash_256};
	if (!(current = get_flags(flags, line)))
		return(0);
	//eval[current - 1](flags);
	ft_putendl("supposed to do a function");
	printf("md5: %d, sha: %d p: %d q: %d r: %d s:%d\n", flags->md5, flags->sha256, flags->prompt, flags->quiet, flags->reverse, flags->string);
	ft_lstiter(flags->filename, printlst);
	free(line);
	return(1);
}

void read_prompt_first(t_flags *flags)
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
		if (!parse_ssl_line(flags, line))
			print_usage_ssl();
		ft_putstr("ft_ssl> ");

	}
}

//temporary
// int get_command(char * command)
// {

// }

int main(int argc, char **argv)
{
	t_flags flags = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	// ft_putstr("argc: ");
	// ft_putnbr(argc);
	// ft_putendl("");
	char *str;
	str = get_file("test");
	printf("%s\n", str);
	ft_strdel(&str);
	if (argc <= 1)
	{
		read_prompt_first(&flags);
	}
	else if (!parse_ssl_line(&flags, argv_to_str(argv, argc)))
		print_usage_ssl();
	return 0;
}