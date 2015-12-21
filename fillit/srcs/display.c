/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 17:39:38 by svelhinh          #+#    #+#             */
/*   Updated: 2015/12/21 19:08:19 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int			ft_check(char **tab, t_coord *coord, int tablen)
{
	int		x;
	int		y;
	int		blk;

	y = 0;
	blk = 0;
	while (blk < 4)
	{
		x = 0;
		while (x < tablen)
		{
			if ((coord->x[blk] == x && coord->y[blk] == y && tab[y][x] != '.')
						|| coord->x[blk] >= tablen
						|| coord->y[blk] >= tablen)
				return (0);
			else if (coord->x[blk] == x && coord->y[blk] == y
					&& tab[y][x] == '.')
				blk++;
			x++;
		}
		y++;
	}
	return (1);
}

char		**ft_tab_store(char **tab, t_coord *coord, int tablen)
{
	int		x;
	int		y;
	int		blk;

	y = 0;
	blk = 0;
		printf("tablen = %d\n", tablen);
	while (y < tablen)
	{
		x = 0;
		while (x < tablen)
		{
			if (coord->x[blk] == x && coord->y[blk] == y)
			{
				tab[y][x] = coord->c;
				blk++;
			}
			x++;
		}
		printf("%s\n", tab[y]);
		y++;
	}
	return (tab);
}

/*void		ft_display(t_coord **coord, int tablen)
{
	char	**tab;
	int		y;
	int		x;

	y = 0;
	x = 0;
	tab = NULL;
	tab = ft_empty(tab);
	while (*coord)
	{
		if (x == 0)
			ft_upper_left(coord, x, y);
		if (ft_check(tab, coord, tablen))
		{
			tab = ft_tab_store(tab, coord);
			*coord = (*coord)->next;
			x = 0;
			printf("\n");
		}
		else
		{
			ft_upper_left(coord, x, y);
			x++;
		}
	}
	printf("\n");
}*/
