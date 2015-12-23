/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 13:56:17 by svelhinh          #+#    #+#             */
/*   Updated: 2015/12/23 13:46:48 by stoussay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
	if (!(tab = (char **)malloc(sizeof(char *) * tablen + 1)))
	{
		ft_putstr("error\n");
		exit(0);
	}
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
