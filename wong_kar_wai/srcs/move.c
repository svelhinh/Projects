/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 17:05:41 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/30 19:26:11 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong_kar_wai.h"

static int	**key_up(int **tab, int x, int y)
{
	int y2;

	y2 = y;
	while (y - 1 >= 0 && tab[y - 1][x] == 0)
		y--;
	if (tab[y][x] == 0)
	{
		tab[y][x] = tab[y2][x];
		tab[y2][x] = 0;
	}
	return (tab);
}

static int	**key_down(int **tab, int x, int y)
{
	int y2;

	y2 = y;
	while (y + 1 <= 3 && tab[y + 1][x] == 0)
		y++;
	if (tab[y][x] == 0)
	{
		tab[y][x] = tab[y2][x];
		tab[y2][x] = 0;
	}
	return (tab);
}

static int	**key_left(int **tab, int x, int y)
{
	int x2;

	x2 = x;
	while (x - 1 >= 0 && tab[y][x - 1] == 0)
		x--;
	if (tab[y][x] == 0)
	{
		tab[y][x] = tab[y][x2];
		tab[y][x2] = 0;
	}
	return (tab);
}

static int	**key_right(int **tab, int x, int y)
{
	int x2;

	x2 = x;
	while (x + 1 <= 3 && tab[y][x + 1] == 0)
		x++;
	if (tab[y][x] == 0)
	{
		tab[y][x] = tab[y][x2];
		tab[y][x2] = 0;
	}
	return (tab);
}

int			**ft_move(int **tab, int key)
{
	int x;
	int y;

	y = (key == KEY_UP) ? (1) : (0);
	while (y < ((key == KEY_DOWN) ? (3) : (4)))
	{
		x = (key == KEY_LEFT) ? (1) : (0);
		while (x < ((key == KEY_RIGHT) ? (3) : (4)))
		{
			if (tab[y][x])
			{
				(key == KEY_UP) ? (tab = key_up(tab, x, y)) : (0);
				(key == KEY_DOWN) ? (tab = key_down(tab, x, y)) : (0);
				(key == KEY_LEFT) ? (tab = key_left(tab, x, y)) : (0);
				(key == KEY_RIGHT) ? (tab = key_right(tab, x, y)) : (0);
			}
			x++;
		}
		y++;
	}
	return (tab);
}
