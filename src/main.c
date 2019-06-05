/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 12:31:33 by ggregoir          #+#    #+#             */
/*   Updated: 2019/06/05 23:12:57 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void printlst(t_list *elem)
{
	ft_putstr("list elem: ");
	ft_putendl(elem->data);
}

int	handle_filename(char *cmd, t_hash *hash)
{
	ft_putstr("filename len: ");
	ft_putnbr(ft_strlen(cmd));
	ft_putendl("");
	ft_lst_add_back(&hash->queue, ft_lstnew(cmd, ft_strlen(cmd) + 1));
	return(1);
}

int	handle_string(char *cmd, t_hash *hash)
{
	int i;
	int y;
	char new[255];
	y = 0;
	i = 1;
	new[0] = -1;
	while(cmd[y] != '\0')
	{
		new[i] = cmd[y];
		i++;
		y++;
	}
	new[i] = cmd[y];
	ft_putstr("string len: ");
	ft_putnbr(ft_strlen(new));
	ft_putendl("");
	ft_lst_add_back(&hash->queue, ft_lstnew(new, ft_strlen(new) + 1));
	return(1);
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



int	get_command(char *command, int8_t *flags, t_hash *hash)
{
	ft_putstr("command from get_command: ");
	ft_putendl(command);

	if (flags['s'])
	{
		handle_string(command, hash);
		flags['s'] = 0;
		return(1);
	}
	if (hash->md5 == 0 && hash->sha256 == 0)
		if (!(ft_strequ(command, "md5")) && !(ft_strequ(command, "sha256")))
			return(ft_ssl_error(command));
		else if (ft_strequ(command, "md5"))
			hash->md5 = 1;
		else
			hash->sha256 = 1;
	else
	{
		if (!flags['-'] && command[0] == '-')
		{
			if (!handle_flags(command, flags))
				return(0);
		}
		else
			handle_filename(command, hash);

	}
	return(1);
}

int args_numbers(t_hash *hash)
{
	if (hash->md5)
	{
		if(!hash->queue->data)
			return(1);
		else
			return(2);
	}
	if (hash->sha256)
	{
		if(!hash->queue->data)
			return(3);
		else
			return(4);
	}
	return(0);
}

int get_args(int8_t *flags, t_hash *hash, char *line)
{
	int i;
	char command[255];
	int j;

	i = 0;
	j = 0;
	while(line[i] != '\0')
	{
		while(line[i] == ' ' || line[i] == '	')
			i++;
		while(line[i] != ' ' && line[i] != '	' && line[i] != '\0')
			command[j++] = line[i++];
		command[j] = '\0';
		if (!get_command(command, flags, hash))
			return(0);
		j = 0;
	}
	return (args_numbers(hash));
}

int	parse_ssl_line(int8_t *flags, t_hash *hash, char *line)
{
	uint8_t current;
	static void	(*eval[4])() = {prompt_md5, hash_md5, prompt_256, hash_256};
	if (!(current = get_args(flags, hash, line)))
		return(0);
	eval[current - 1](flags));
	ft_putendl("supposed to do a function");
	printf("md5: %d, sha: %d p: %d q: %d r: %d s:%d\n", hash->md5, hash->sha256, flags['p'], flags['q'], flags['r'], flags['s']);
	ft_lstiter(hash->queue, printlst);
	free(line);
	return(1);
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
		if (!parse_ssl_line(flags, hash, line))
			print_usage_ssl();
		ft_putstr("ft_ssl> ");

	}
}

int main(int argc, char **argv)
{
	int i;
	int8_t flags[128];
	t_hash hash = {0, 0, 0, 0};
	i = 0;
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
	else if (!parse_ssl_line(flags, &hash, argv_to_str(argv, argc)))
		print_usage_ssl();
	return 0;
}