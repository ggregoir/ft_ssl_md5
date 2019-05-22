/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 12:31:33 by ggregoir          #+#    #+#             */
/*   Updated: 2019/05/22 17:41:43 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"


int	handle_filename(char *command, t_flags *flags)
{
	ft_putstr("filename: ");
	ft_putendl(command);
}

int	handle_flags(char *command, t_flags *flags)
{
	if (ft_strequ(command, "md5"))
	{
		flags->noflags = 1;
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
		if (!flags->noflags)
		{
			if(command[0] == '-')
				handle_flags(command, flags);
		}
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
	printf("md5: %d, sha: %d\n", flags->md5, flags->sha256);
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
	t_flags flags = {0, 0, 0, 0, 0, "", 0};
	// ft_putstr("argc: ");
	// ft_putnbr(argc);
	// ft_putendl("");
	if (argc <= 1)
	{
		read_prompt_first(&flags);
	}
	else if (!parse_ssl_line(&flags, argv_to_str(argv, argc)))
		print_usage_ssl();
	return 0;
}