/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 14:32:29 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/31 19:15:32 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong_kar_wai.h"

static int	**key_left(int **tab, int x, int y)
{
	int x2;
	int cnt;

	x2 = x;
	cnt = 1;
	while (x - 1 > 0 && tab[y][x - 1] == 0)
		x--;
	x--;
	if (tab[y][x2] == tab[y][x])
	{
		while (x >= 0 && tab[y][x] == tab[y][x2])
		{
			cnt++;
			x--;
		}
		if (cnt == 2 || cnt == 4)
		{
			tab[y][x2] *= 2;
			(cnt == 2) ? (tab[y][x + 1] = 0) : (0);
			(cnt == 4) ? (tab[y][x2 - 1] = 0) : (0);
		}
	}
	return (tab);
}

static int	**key_up(int **tab, int x, int y)
{
	int y2;
	int cnt;

	y2 = y;
	cnt = 1;
	while (y - 1 > 0 && tab[y - 1][x] == 0)
		y--;
	y--;
	if (tab[y2][x] == tab[y][x])
	{
		while (y >= 0 && tab[y][x] == tab[y2][x])
		{
			cnt++;
			y--;
		}
		if (cnt == 2 || cnt == 4)
		{
			tab[y2][x] *= 2;
			(cnt == 2) ? (tab[y + 1][x] = 0) : (0);
			(cnt == 4) ? (tab[y2 - 1][x] = 0) : (0);
		}
	}
	return (tab);
}

int			**check_keys2(int **tab, int key)
{
	int x;
	int y;

	y = 3;
	while (y >= (key == KEY_UP) ? (1) : (0))
	{
		x = 3;
		while (x >= (key == KEY_LEFT) ? (1) : (0))
		{
			if (tab[y][x])
			{
				(key == KEY_UP) ? (tab = key_up(tab, x, y)) : (0);
				(key == KEY_LEFT) ? (tab = key_left(tab, x, y)) : (0);
			}
			x--;
		}
		y--;
	}
	return (tab);
}
