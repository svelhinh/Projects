/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 14:54:58 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/24 11:56:19 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strend(char *str, int len)
{
	while (str[len])
		len++;
	return (len);
}

char	*ft_read(char *swap, size_t fd)
{
	char	*tmp;
	char	*buf;
	size_t	ret;

	buf = ft_strnew(BUFF_SIZE);
	while (!ft_strchr(swap, '\n') && (ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		tmp = ft_strdup(swap);
		if (swap)
			free(swap);
		swap = ft_strjoin(tmp, buf);
		if (tmp)
			free(tmp);
	}
	(buf) ? (free(buf)) : (0);
	return (swap);
}

int		get_next_line(int const fd, char **line)
{
	static char		*swap = NULL;
	char			*buf;
	size_t			start;

	buf = ft_strnew(0);
	if (fd == -1 || read(fd, buf, 0) == -1 || !line)
		return (-1);
	(buf) ? (free(buf)) : (0);
	(!swap) ? (swap = ft_strnew(BUFF_SIZE)) : (0);
	swap = ft_read(swap, fd);
	if (ft_strchr(swap, '\n'))
	{
		start = 0;
		while (swap[start] != '\n')
			start++;
		*line = ft_strsub(swap, 0, start);
		swap = ft_strsub(swap, start + 1, ft_strend(swap, start));
		return (1);
	}
	if (swap[0] != '\0' && (*line = ft_strdup(swap)))
	{
		ft_bzero(swap, ft_strlen(swap));
		return (1);
	}
	return (0);
}
