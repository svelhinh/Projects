/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 13:56:17 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/02 10:44:19 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_init(int *nblines, int *error, int *gnlret)
{
	*nblines = 0;
	*error = 0;
	*gnlret = 1;
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
	v.contact = 0;
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

void		ft_check_tetri(int fd)
{
	char	buf[BUFF_SIZE];
	t_varf	v;

	v.file = ft_strnew(1);
	while ((v.ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[v.ret] = '\0';
		v.file = ft_strjoin(v.file, buf);
	}
	if (v.file[0] != '.' && v.file[0] != '#')
		ft_exit();
	ft_tmblk(v.file);
	ft_contact(v);
	(v.file[ft_strlen(v.file) - 1] == '\n'
	&& v.file[ft_strlen(v.file) - 2] == '\n') ? (ft_exit()) : (0);
	free(v.file);
}
