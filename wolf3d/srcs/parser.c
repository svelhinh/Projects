/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/23 12:31:58 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/23 14:49:00 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static	int number_lines(char *lvl)
{
	int		fd;
	int		nblines;
	char	*line;

	nblines = 0;
	if ((fd = open(lvl, O_RDONLY)) == -1)
		ft_exit("open() failed in parser()");
	while (get_next_line(fd, &line) > 0)
	{
		ft_strdel(&line);
		nblines++;
	}
	ft_strdel(&line);
	(close(fd) == -1) ? (ft_exit("close() failed in parser()")) : (0);
	return (nblines);
}

char		**parser(char *lvl)
{
	int		fd;
	char	*line;
	char	**tab_lvl;
	int		i;
	int		nblines;

	i = 0;
	nblines = number_lines(lvl);
	if (!(tab_lvl = (char **)malloc(sizeof(char *) * nblines + 1)))
		ft_exit("malloc() tab in number_lines() failed");
	if ((fd = open(lvl, O_RDONLY)) == -1)
		ft_exit("open() failed in parser()");
	while (get_next_line(fd, &line) > 0)
	{
		tab_lvl[i] = ft_strdup(line);
		ft_strdel(&line);
		i++;
	}
	ft_strdel(&line);
	tab_lvl[i] = NULL;
	if (close(fd) == -1)
		ft_exit("close() failed in parser()");
	return (tab_lvl);
}
