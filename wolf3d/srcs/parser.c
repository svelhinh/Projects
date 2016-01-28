/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/23 12:31:58 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/28 12:17:42 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static	int	number_lines(char *lvl)
{
	int		fd;
	int		nblines;
	char	*line;

	nblines = 0;
	if ((fd = open(lvl, O_RDONLY)) == -1)
		ft_exit("open() failed in number_lines()");
	while (get_next_line(fd, &line) > 0)
	{
		ft_strdel(&line);
		nblines++;
	}
	ft_strdel(&line);
	(close(fd) == -1) ? (ft_exit("close() failed in number_lines()")) : (0);
	return (nblines);
}

static int	*split(char *s)
{
	int		*tab;
	char	**tmp;
	int		i;

	i = 0;
	if (!(tab = (int *)malloc(sizeof(int) * (ft_strlen(s) + 1))))
		ft_exit("malloc() tab in split() failed");
	tmp = ft_strsplit(s, ' ');
	while (tmp[i])
	{
		tab[i] = ft_atoi(tmp[i]);
		ft_strdel(&tmp[i]);
		i++;
	}
	return (tab);
}

int			**parser(char *lvl)
{
	int		fd;
	char	*line;
	int		**map;
	int		i;
	int		nblines;

	i = 0;
	nblines = number_lines(lvl);
	if (!(map = (int **)malloc(sizeof(int *) * nblines)))
		ft_exit("malloc() tab in number_lines() failed");
	if ((fd = open(lvl, O_RDONLY)) == -1)
		ft_exit("open() failed in parser()");
	while (get_next_line(fd, &line) > 0)
	{
		map[i] = split(line);
		ft_strdel(&line);
		i++;
	}
	ft_strdel(&line);
	map[i] = NULL;
	(close(fd) == -1) ? (ft_exit("close() failed in parser()")) : (0);
	return (map);
}
