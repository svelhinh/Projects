/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 15:19:46 by svelhinh          #+#    #+#             */
/*   Updated: 2018/07/30 17:26:43 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

char			*get_str_command(void)
{
	if (g_command == CM_MD5)
		return ("md5");
	if (g_command == CM_SHA256)
		return ("sha256");
	return ("");
}

char			*read_file(char *path, size_t *msg_len, int print_errors)
{
	int		fd;
	int		total_rd;
	int		rd;
	char	buf[513];
	char	*str;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		(print_errors) ? (print_error(ER_WRONG_FILE, NULL, path)) : (0);
		return (NULL);
	}
	str = (char *)ft_memalloc(1);
	(print_errors) ? (ft_test_malloc(str)) : (0);
	total_rd = 0;
	while ((rd = read(fd, buf, 512)) != 0)
	{
		if (rd == -1)
		{
			(print_errors) ? (print_error(ER_READ_FILE, NULL, path)) : (0);
			break ;
		}
		str = ft_strnnjoin(str, buf, total_rd, rd);
		total_rd += rd;
	}
	close(fd);
	*msg_len = total_rd;
	return (str);
}

char			*read_stdin(size_t *msg_len)
{
	int		fd;
	int		rd;
	int		total_rd;
	char	buf[513];
	char	*str;

	fd = 0;
	fcntl(0, F_SETFL, fcntl(0, F_GETFL) | O_NONBLOCK);		// Non blocking read from stdin
	str = (char *)ft_memalloc(1);
	ft_test_malloc(str);
	total_rd = 0;
	while ((rd = read(fd, buf, 512)) != 0)
	{
		if (rd == -1)
			return (NULL);
		str = ft_strnnjoin(str, buf, total_rd, rd);
		total_rd += rd;
	}
	close(fd);
	*msg_len = total_rd;
	return (str);
}

void			append_msg(char *file, char *msg, size_t msg_len, int stdin)
{
	g_nb_msg++;
	g_ssl = (t_ssl *)realloc(g_ssl, sizeof(t_ssl) * g_nb_msg);
	ft_test_malloc(g_ssl);
	g_ssl[g_nb_msg - 1].file = file;
	g_ssl[g_nb_msg - 1].stdin = stdin;
	g_ssl[g_nb_msg - 1].msg = msg;
	g_ssl[g_nb_msg - 1].msg_len = msg_len;
	print_msg_digest(g_nb_msg - 1);
}
