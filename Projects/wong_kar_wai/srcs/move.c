/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 17:05:41 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/31 19:15:56 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong_kar_wai.h"

static int	**key_up(int **tab, int x, int y, int *ret)
{
	int y2;

	y2 = y;
	while (y - 1 >= 0 && tab[y - 1][x] == 0)
		y--;
	if (tab[y][x] == 0)
	{
		tab[y][x] = tab[y2][x];
		tab[y2][x] = 0;
		*ret = 1;
	}
	return (tab);
}

static int	**key_left(int **tab, int x, int y, int *ret)
{
	int x2;

	x2 = x;
	while (x - 1 >= 0 && tab[y][x - 1] == 0)
		x--;
	if (tab[y][x] == 0)
	{
		tab[y][x] = tab[y][x2];
		tab[y][x2] = 0;
		*ret = 1;
	}
	return (tab);
}

int			**ft_move(int **tab, int key, int *ret)
{
	int x;
	int y;

	if (key == KEY_UP || key == KEY_LEFT)
	{
		y = (key == KEY_UP) ? (1) : (0);
		while (y < 4)
		{
			x = (key == KEY_LEFT) ? (1) : (0);
			while (x < 4)
			{
				if (tab[y][x])
				{
					(key == KEY_UP) ? (tab = key_up(tab, x, y, ret)) : (0);
					(key == KEY_LEFT) ? (tab = key_left(tab, x, y, ret)) : (0);
				}
				x++;
			}
			y++;
		}
	}
	else
		tab = ft_move2(tab, key, ret);
	return (tab);
}
