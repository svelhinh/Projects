/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 15:01:39 by svelhinh          #+#    #+#             */
/*   Updated: 2015/12/23 17:36:10 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_tetri(char *coord)
{
	int x;
	int blk;
	int i;

	x = 0;
	i = 0;
	blk = 0;
	while (coord[x])
	{
		if (coord[x] == '#' && coord[x + 4] != '#'
				&& coord[x + 1] != '#' && coord[x - 1] != '#'
				&& coord[x - 4] != '#')
			return (-1);
		x++;
	}
	return (0);
}

static int		ft_line(char *line, int *blk)
{
	int	x;

	x = 0;
	while (line[x])
	{
		if (line[x] != '#' && line[x] != '.')
			return (-1);
		if (line[x] == '#')
			(*blk)++;
		x++;
	}
	if (x != 4)
		return (-1);
	return (0);
}

static int		ft_endblk(char *coord, int *nblines, int *blk)
{
	if (ft_tetri(coord) == -1 || *nblines != 4 || *blk != 4)
		return (-1);
	*nblines = 0;
	*blk = 0;
	return (0);
}

static int		ft_nblines(char *line, int fd, char ***file)
{
	t_varf	v;

	v.coord = ft_strnew(16);
	ft_init(&v.nblines, &v.error, &v.gnlret, &v.blk);
	while (v.gnlret && !v.error)
	{
		if (!(v.gnlret = get_next_line(fd, &line)))
			return (0);
		if (ft_strcmp(line, "\0") && ++v.nblines)
		{
			v.coord = ft_strjoin(v.coord, line);
			**file = ft_strjoin(**file, line);
			(v.gnlret) ? (v.error = ft_line(line, &v.blk)) : (42);
			if (v.error == -1)
				return (-1);
		}
		else
		{
			if ((v.error = ft_endblk(v.coord, &v.nblines, &v.blk) == -1))
				return (-1);
			ft_strdel(&v.coord);
			v.coord = ft_strnew(16);
		}
	}
	return (0);
}

int				ft_errors(int fd, char **file)
{
	t_varf v;

	v.error = 0;
	if (((v.line = (char *)malloc(sizeof(char) * BUFF_SIZE + 1)) == NULL))
		return (-1);
	v.error = ft_nblines(v.line, fd, &file);
	return (v.error);
}
