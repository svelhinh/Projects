/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 15:33:40 by svelhinh          #+#    #+#             */
/*   Updated: 2018/07/30 17:13:02 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static int	cmd_has_file(char **args, int len)
{
	int		arg_i;
	char	*s;
	size_t	msg_len;

	arg_i = 2;
	while (arg_i < len)
	{
		if (!ft_strcmp(args[arg_i], "-s"))
			arg_i++;
		else if (ft_strcmp(args[arg_i], "-p") &&
			ft_strcmp(args[arg_i], "-q") && ft_strcmp(args[arg_i], "-r"))
		{
			while (arg_i < len)
			{
				s = read_file(args[arg_i], &msg_len, 0);
				if (s)
					return (1);
				arg_i++;
			}
			break ;
		}
		arg_i++;
	}
	return (0);
}

static void	execute_options(char **args, int len)
{
	char	*s;
	int		arg_i;
	size_t	msg_len;

	arg_i = 1;
	while (++arg_i < len)
	{
		if (!ft_strcmp(args[arg_i], "-s"))
		{
			arg_i++;
			(!args[arg_i]) ? (print_error(ER_SUM_NO_STRING, NULL, NULL)) :
				(append_msg(NULL, args[arg_i], ft_strlen(args[arg_i]), 0));
		}
		else if (ft_strcmp(args[arg_i], "-p") && ft_strcmp(args[arg_i], "-q")
			&& ft_strcmp(args[arg_i], "-r"))
		{
			while (arg_i < len)
			{
				s = read_file(args[arg_i], &msg_len, 1);
				if (s)
					append_msg(args[arg_i], s, msg_len, 0);
				arg_i++;
			}
			break ;
		}
	}
}

static void	parse_options(char **args, int len)
{
	int		arg_i;
	char	*s;
	int		has_at_least_one_file;
	size_t	msg_len;

	has_at_least_one_file = 0;
	arg_i = 2;
	while (arg_i < len)
	{
		if (!ft_strcmp(args[arg_i], "-p"))
			g_options |= OP_PRINT;
		else if (!ft_strcmp(args[arg_i], "-q"))
			g_options |= OP_QUIET;
		else if (!ft_strcmp(args[arg_i], "-r"))
			g_options |= OP_REVERSE;
		arg_i++;
	}
	if (!(g_options & OP_PRINT))
		has_at_least_one_file = cmd_has_file(args, len);
	if ((s = read_stdin(&msg_len)) && (g_options & OP_PRINT || !has_at_least_one_file))
		append_msg(NULL, s, msg_len, 1);
	execute_options(args, len);
}

void		parse_command_line(char **args, int len)
{
	if (len == 1)
		print_error(ER_USAGE, NULL, NULL);
	else
	{
		if (!ft_strcmp(args[1], "md5"))
		{
			g_command = CM_MD5;
			parse_options(args, len);
		}
		else if (!ft_strcmp(args[1], "sha256"))
		{
			g_command = CM_SHA256;
			parse_options(args, len);
		}
		else
			print_error(ER_INVALID_COMMAND, args[1], NULL);
	}
}
