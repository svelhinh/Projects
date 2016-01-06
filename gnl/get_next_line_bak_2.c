/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 12:27:29 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/06 14:59:41 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*read_file(char *swap, int fd)
{
	char *buf;
	int ret;

	ret = 0;
	buf = ft_strnew(BUFF_SIZE);
	while (!ft_strchr(swap, '\n') && (ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		swap = ft_strjoin(swap, buf);
	}
	free(buf);
	return (swap);
}

int		get_next_line(int const fd, char **line)
{
	int i;
	int si;
	char *tmp;
	char *buf;
	static char *swap;

	i = 0;
	buf = NULL;
	if (fd < 0 || read(fd, buf, 0) == -1 || !line)
		return (-1);
	if (!swap)
		swap = ft_strnew(0);
	tmp = NULL;
	if (!ft_strchr(swap, '\n'))
		swap = read_file(swap, fd);
	if (swap[0] == '\0')
		return (0);
	if (ft_strchr(swap, '\n'))
	{
		while (swap[i] != '\n')
			i++;
		*line = ft_strsub(swap, 0, i);
		i++;
		si = i;
		while (swap[i])
			i++;
		tmp = ft_strdup(swap);
		free(swap);
		swap = ft_strnew(i - si);
		swap = ft_strsub(tmp, si, i - si);
		free(tmp);
	}
	else
	{
		*line = ft_strdup(swap);
		free(swap);
		swap = ft_strnew(0);
	}
	return (1);
}
