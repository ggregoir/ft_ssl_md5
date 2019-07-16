/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 15:27:11 by ggregoir          #+#    #+#             */
/*   Updated: 2019/07/12 01:25:11 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

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
			hash->sha256 = 3;
		}
		return(1);
}

int		handle_args(int8_t *flags, t_hash *hash, int *i, char **tab)
{
	if (flags['s'])
	{
		do_hash(tab[*i], flags, hash->md5 + hash->sha256);
		flags['s'] = 0;
		hash->prompt = 0;
		return(1);
	}
	if (!flags['-'] && tab[*i][0] == '-')
	{
		if (!handle_flags(tab[*i], flags))
			return(0);
	}
	else if (hash->md5 || hash->sha256)
	{
		hash->prompt = 0;
		flags['-'] = 1;
		do_hash(tab[*i], flags, hash->md5 + hash->sha256 + hash->prompt);
	}
	return(1);
}