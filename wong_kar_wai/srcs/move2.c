/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 14:28:04 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/31 14:35:48 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong_kar_wai.h"

static int	**key_down(int **tab, int x, int y, int *ret)
{
	int y2;

	y2 = y;
	while (y + 1 <= 3 && tab[y + 1][x] == 0)
		y++;
	if (tab[y][x] == 0)
	{
		tab[y][x] = tab[y2][x];
		tab[y2][x] = 0;
		*ret = 1;
	}
	return (tab);
}

static int	**key_right(int **tab, int x, int y, int *ret)
{
	int x2;

	x2 = x;
	while (x + 1 <= 3 && tab[y][x + 1] == 0)
		x++;
	if (tab[y][x] == 0)
	{
		tab[y][x] = tab[y][x2];
		tab[y][x2] = 0;
		*ret = 1;
	}
	return (tab);
}

int			**ft_move2(int **tab, int key, int *ret)
{
	int x;
	int y;

	y = (key == KEY_DOWN) ? (2) : (3);
	while (y >= 0)
	{
		x = (key == KEY_RIGHT) ? (2) : (3);
		while (x >= 0)
		{
			if (tab[y][x])
			{
				(key == KEY_DOWN) ? (tab = key_down(tab, x, y, ret)) : (0);
				(key == KEY_RIGHT) ? (tab = key_right(tab, x, y, ret)) : (0);
			}
			x--;
		}
		y--;
	}
	return (tab);
}
