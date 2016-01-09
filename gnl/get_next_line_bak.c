/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 14:54:58 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/09 17:19:18 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		ft_strend(char *str, int len)
{
	while (str[len])
		len++;
	return (len);
}

char	*ft_read(char *swap, size_t fd)
{
	t_varg	v;
	size_t	i;
	char	*tmp;

	i = 0;
	v.buf = ft_strnew(BUFF_SIZE);
	/*ft_putstr("swap = ");
	ft_putstr(swap);
	ft_putchar('\n');*/
	while (!ft_strchr(swap, '\n') && (v.ret = read(fd, v.buf, BUFF_SIZE)))
	{
		v.buf[v.ret] = '\0';
		tmp = ft_strdup(swap);
		/*if (swap)
			free(swap);*/
		/*ft_putstr("yo1\n");
		ft_putstr("retjoin = ");
		ft_putstr(ft_strjoin(tmp, v.buf));
		ft_putstr("\n");*/
		swap = ft_strjoin(tmp, v.buf);
		//ft_putstr("yo2\n");
		if (tmp)
			free(tmp);
	}
	(v.buf) ? (free(v.buf)) : (0);
	return (swap);
}

int		get_next_line(int const fd, char **line)
{
	static char		*swap = NULL;
	t_varg			var;

	var.len = 0;
	var.buf = ft_strnew(0);
	if (fd == -1 || read(fd, var.buf, 0) == -1 || !line)
		return (-1);
	*line = ft_strnew(0);
	(var.buf) ? (free(var.buf)) : (0);
	(!swap) ? (swap = ft_strnew(BUFF_SIZE)) : (0);
	swap = ft_read(swap, fd);
	if (ft_strchr(swap, '\n'))
	{
		var.start = 0;
		while (swap[var.start] != '\n')
			var.start++;
		*line = ft_strsub(swap, 0, var.start);
		swap = ft_strsub(swap, var.start + 1, ft_strend(swap, var.start));
		return (1);
	}
	if (swap[0] != '\0' && (*line = ft_strdup(swap)))
	{
		ft_bzero(swap, ft_strlen(swap));
		return (1);
	}
	return (0);
}
