/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 14:54:58 by svelhinh          #+#    #+#             */
/*   Updated: 2015/12/31 12:26:25 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strend(char *str, int len)
{
	while (str[len])
		len++;
	return (len);
}

char	*ft_read(char *swap, size_t fd, int *nblines)
{
	t_varg v;
	size_t i;

	i = 0;
	v.buf = ft_strnew(BUFF_SIZE);
	while (!ft_strchr(swap, '\n') && (v.ret = read(fd, v.buf, BUFF_SIZE)))
	{
		v.buf[v.ret] = '\0';
		swap = ft_strjoin(swap, v.buf);
		if (ft_strchr(swap, '\n'))
			while (swap[i])
			{
				if (swap[i] == '\n')
					(*nblines)++;
				i++;
			}
	}
	free(v.buf);
	return (swap);
}

void	ft_plus_plus(size_t *start, size_t *len)
{
	(*start)++;
	(*len)++;
}

int		get_next_line(int const fd, char **line)
{
	static int		nblines = 0;
	static char		*swap = NULL;
	t_varg			var;

	var.len = 0;
	if (fd == -1 || read(fd, var.buf, 0) == -1)
		return (-1);
	(nblines == -1) ? (nblines = 0) : (0);
	(!swap) ? (swap = ft_strnew(BUFF_SIZE)) : (0);
	swap = ft_read(swap, fd, &nblines);
	if (nblines > 0)
	{
		var.start = 0;
		while (swap[var.start] != '\n')
			ft_plus_plus(&var.start, &var.len);
		*line = ft_strsub(swap, 0, var.len);
		swap = ft_strsub(swap, var.start + 1, ft_strend(swap, var.start));
		nblines--;
		return (1);
	}
	if (swap[0] != '\0' && nblines-- == 0 && (*line = ft_strdup(swap))
			&& (swap = ft_strnew(BUFF_SIZE)))
		return (1);
	return (0);
}
