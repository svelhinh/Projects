/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 12:50:17 by svelhinh          #+#    #+#             */
/*   Updated: 2015/12/19 14:53:19 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		ft_check_len(t_coord *coord, int tablen)
{
	int blk;

	blk = 0;
	while (blk < 4)
	{
		if (coord->x[blk] >= tablen || coord->y[blk] >= tablen)
			return (0);
		blk++;
	}
	return (1);
}

void	jesaispas(t_coord *first)
{
	t_coord *coord;
	char **tab;
	int tablen;
	int x;
	int y;
	int i;
	int j;

	tablen = 2;
	y = tablen;
	tab = NULL;
	coord = first;
	tab = ft_empty(tab, tablen);
	i = 0;
	j = 0;
	x = 0;
	y = 0;
	while (coord)
	{
		ft_move(&coord, x, y);
		while (!ft_check_len(coord, tablen) && y < tablen)
		{
			x++;
			if (x == tablen)
			{
				x = 0;
				y++;
			}
			ft_move(&coord, x, y);
		}
		if (ft_check_len(coord, tablen))
		{
			tab = ft_tab_store(tab, &coord);
			coord = coord->next;
			i++;
		}
		else if (y >= tablen)
		{
			if (coord == first)
			{
				tablen++;
				tab = ft_empty(tab, tablen);
				x = 0;
				y = 0;
			}
			else
			{
				coord = first;
				while (j < i - 1)
				{
					coord = coord->next;
					i++;
				}
				x++;
			}
		}
	}
}
