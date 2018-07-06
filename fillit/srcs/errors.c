/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 15:01:39 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/02 10:55:29 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			ft_contact(t_varf v)
{
	v.contact = 0;
	v.nblines = 0;
	v.i = 0;
	while (v.file[v.i])
	{
		if (v.file[v.i] == '#')
		{
			(v.file[v.i + 1] == '#') ? (v.contact++) : ('y');
			(v.file[v.i - 1] == '#') ? (v.contact++) : ('y');
			(v.file[v.i + 5] == '#' && v.nblines != 3) ? (v.contact++) : ('y');
			(v.file[v.i - 5] == '#' && v.nblines != 0) ? (v.contact++) : ('y');
		}
		(v.file[v.i] == '\n') ? (v.nblines++) : ('y');
		if (v.nblines == 4)
		{
			(v.contact < 6 || v.contact > 8) ? (ft_exit()) : (0);
			v.contact = 0;
			v.nblines = 0;
			v.i++;
		}
		v.i++;
	}
}

static void		ft_line(char *line)
{
	int	x;

	x = 0;
	while (line[x])
	{
		if (line[x] != '#' && line[x] != '.')
			ft_exit();
		x++;
	}
	if (x != 4)
		ft_exit();
}

static int		ft_nblines(char *line, int fd, char ***file)
{
	t_varf	v;

	ft_init(&v.nblines, &v.error, &v.gnlret);
	while (v.gnlret && !v.error)
	{
		if (!(v.gnlret = get_next_line(fd, &line)))
		{
			(v.nblines != 4) ? (ft_exit()) : (0);
			return (0);
		}
		if (ft_strcmp(line, "\0") && ++v.nblines <= 4)
		{
			**file = ft_strjoin(**file, line);
			(v.gnlret) ? (ft_line(line)) : (0);
			if (v.error == -1)
				return (-1);
		}
		else
		{
			if (v.nblines != 4)
				return (-1);
			v.nblines = 0;
		}
	}
	return (0);
}

void			ft_errors(int fd, char **file)
{
	t_varf v;

	v.line = ft_strnew(BUFF_SIZE);
	if (ft_nblines(v.line, fd, &file) == -1)
		ft_exit();
}
