/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 14:54:58 by svelhinh          #+#    #+#             */
/*   Updated: 2015/12/26 10:31:19 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strend(char *str, int start)
{
	while (str[start])
		start++;
	return (start);
}

char	*ft_read(char *swap, size_t fd, int *nblines, size_t *start)
{
	t_varg v;

	*start = 0;
	while (!ft_strchr(swap, '\n') && (v.ret = read(fd, v.buf, BUFF_SIZE)))
	{
		v.buf[v.ret] = '\0';
		swap = ft_strjoin(swap, v.buf);
		if (ft_strchr(swap, '\n'))
			while (swap[*start])
			{
				if (swap[*start] == '\n')
					(*nblines)++;
				(*start)++;
			}
	}
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
	char			*tmp;

	tmp = NULL;
	var.len = 0;
	if (fd == -1 || read(fd, tmp, 0))
		return (-1);
	(!swap) ? (swap = ft_strnew(BUFF_SIZE + 1)) : ("yo");
	swap = ft_read(swap, fd, &nblines, &var.start);
	if (nblines > 0 && ft_strchr(swap, '\n'))
	{
		var.start = 0;
		while (swap[var.start] != '\n')
			ft_plus_plus(&var.start, &var.len);
		*line = ft_strsub(swap, 0, var.len);
		swap = ft_strsub(swap, var.start + 1, ft_strend(swap, var.start));
		nblines--;
		return (1);
	}
	if (nblines-- == 0)
	{
		*line = ft_strdup(swap);
		return (1);
	}
	return (0);
}
