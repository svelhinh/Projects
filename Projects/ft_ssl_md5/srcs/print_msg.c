/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 18:31:30 by svelhinh          #+#    #+#             */
/*   Updated: 2018/07/30 16:51:17 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void	print_reverse(int msg_i)
{
	ft_putstr(g_ssl[msg_i].msg_digest);
	ft_putchar(' ');
	if (g_ssl[msg_i].file)
		ft_putendl(g_ssl[msg_i].file);
	else
	{
		ft_putstr("\"");
		ft_putstr(g_ssl[msg_i].msg);
		ft_putendl("\"");
	}
}

static void	print_msg(int msg_i)
{
	ft_putstr(ft_str_toupper(get_str_command()));
	ft_putstr(" (");
	if (g_ssl[msg_i].file)
		ft_putstr(g_ssl[msg_i].file);
	else
	{
		ft_putstr("\"");
		ft_putstr(g_ssl[msg_i].msg);
		ft_putstr("\"");
	}
	ft_putstr(") = ");
	ft_putendl(g_ssl[msg_i].msg_digest);
}

void		print_msg_digest(int msg_i)
{
	unsigned char	*(*hash_f[2]) (unsigned char *, unsigned int);

	hash_f[0] = md5;
	hash_f[1] = sha256;
	g_ssl[msg_i].msg_digest =
		(char *)(*hash_f[g_command - 1])((unsigned char *)g_ssl[msg_i].msg,
		g_ssl[msg_i].msg_len);
	if (!(g_options & OP_QUIET) && !g_ssl[msg_i].stdin)
	{
		if (g_options & OP_REVERSE)
			print_reverse(msg_i);
		else
			print_msg(msg_i);
	}
	else if (!(g_options & OP_PRINT && g_ssl[msg_i].stdin))
		ft_putendl(g_ssl[msg_i].msg_digest);
	if (g_options & OP_PRINT && g_ssl[msg_i].stdin)
	{
		ft_putstr(g_ssl[msg_i].msg);
		ft_putendl(g_ssl[msg_i].msg_digest);
	}
}
