/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 13:56:17 by svelhinh          #+#    #+#             */
/*   Updated: 2015/12/30 19:21:15 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void		ft_init(int *nblines, int *error, int *gnlret, int *blk)
{
	*nblines = 0;
	*error = 0;
	*gnlret = 1;
	*blk = 0;
}

char		*ft_letters(char *file)
{
	int		cnt;
	char	c;
	int		i;

	c = 'A';
	i = 0;
	cnt = 0;
	while (file[i])
	{
		if (file[i] == '#')
		{
			file[i] = c;
			cnt++;
		}
		if (cnt == 4)
		{
			cnt = 0;
			c++;
		}
		i++;
	}
	return (file);
}

char		**ft_empty(char **tab, int tablen)
{
	int y;
	int x;

	y = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * (tablen + 1))))
		return (NULL);
	while (y < tablen)
	{
		tab[y] = ft_strnew(tablen);
		x = 0;
		while (x < tablen)
		{
			tab[y][x] = '.';
			x++;
		}
		y++;
	}
	tab[y] = NULL;
	return (tab);
}

void		ft_tmblk(char *file)
{
	t_varf v;

	v.i = 0;
	v.nblines = 0;
	v.blk = 0;
	while (file[v.i])
	{
		if (v.nblines < 4)
		{
			if (file[v.i] == '\n')
				v.nblines++;
			if (file[v.i] == '#')
				v.blk++;
		}
		if (v.nblines == 4)
		{
			if (v.blk != 4)
				ft_exit();
			v.blk = 0;
			v.nblines = 0;
			v.i++;
		}
		v.i++;
	}
}

void		ft_check_endl(int fd)
{
	char	buf[BUFF_SIZE];
	t_varf	v;

	v.i = 0;
	v.file = ft_strnew(1);
	v.contact = 0;
	while ((v.ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[v.ret] = '\0';
		v.file = ft_strjoin(v.file, buf);
	}
	ft_tmblk(v.file);
	while (v.file[v.i])
	{
		printf("contact = %d\nnblines = %d\n\n", v.contact, v.nblines);
		if (v.file[v.i] == '#')
		{
			(v.file[v.i + 1] == '#') ? (v.contact++) : ('y');
			(v.file[v.i - 1] == '#') ? (v.contact++) : ('y');
			(v.file[v.i + 5] == '#') ? (v.contact++) : ('y');
			(v.file[v.i - 5] == '#') ? (v.contact++) : ('y');
		}
		if (v.file[v.i] == '\n')
			v.nblines++;
		if (v.nblines == 5)
		{
			if (v.contact < 6 || v.contact > 8)
				ft_exit();
			v.contact = 0;
			v.nblines = 0;
			v.i++;
		}
		v.i++;
	}
	if (v.file[ft_strlen(v.file) - 1] == '\n' && v.file[ft_strlen(v.file) - 2] == '\n')
		ft_exit();
}
