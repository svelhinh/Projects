/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 16:48:29 by svelhinh          #+#    #+#             */
/*   Updated: 2018/07/23 20:26:15 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void	print_error2(t_errors error, char *file)
{
	if (error == ER_READ_FILE)
	{
		ft_putstr("ft_ssl: ");
		ft_putstr(get_str_command());
		ft_putstr(": ");
		ft_putstr(file);
		ft_putendl(": Read failed");
	}
	else if (error == ER_READ_STDIN)
	{
		ft_putstr("ft_ssl: ");
		ft_putstr(get_str_command());
		ft_putendl(": Read stdin failed");
	}
	else if (error == ER_SUM_NO_STRING)
	{
		ft_putstr("ft_ssl: ");
		ft_putstr(get_str_command());
		ft_putendl(": -s: No string given");
	}
}

void		print_error(t_errors error, char *command, char *file)
{
	if (g_options & OP_QUIET)
		return ;
	if (error == ER_USAGE)
		ft_puterror("usage: ft_ssl command [command opts] [command args]");
	else if (error == ER_INVALID_COMMAND)
	{
		ft_putstr("ft_ssl: Error: '");
		ft_putstr(command);
		ft_puterror("' is an invalid command.\n\nStandard commands:\n\n\
Message Digest commands:\nmd5\nsha256\n\nCipher commands:");
	}
	else if (error == ER_WRONG_FILE)
	{
		ft_putstr("ft_ssl: ");
		ft_putstr(get_str_command());
		ft_putstr(": ");
		ft_putstr(file);
		ft_putendl(": No such file or directory");
	}
	print_error2(error, file);
}
