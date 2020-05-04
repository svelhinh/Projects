/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 16:47:27 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/31 19:21:27 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong_kar_wai.h"

static int	**key_down(int **tab, int x, int y)
{
	int y2;
	int cnt;

	y2 = y;
	cnt = 1;
	while (y + 1 < 3 && tab[y + 1][x] == 0)
		y++;
	y++;
	if (tab[y2][x] == tab[y][x])
	{
		while (y < 4 && tab[y][x] == tab[y2][x])
		{
			cnt++;
			y++;
		}
		if (cnt == 2 || cnt == 4)
		{
			tab[y2][x] *= 2;
			(cnt == 2) ? (tab[y - 1][x] = 0) : (0);
			(cnt == 4) ? (tab[y2 + 1][x] = 0) : (0);
		}
	}
	return (tab);
}

static int	**key_right(int **tab, int x, int y)
{
	int x2;
	int cnt;

	x2 = x;
	cnt = 1;
	while (x + 1 < 3 && tab[y][x + 1] == 0)
		x++;
	x++;
	if (tab[y][x2] == tab[y][x])
	{
		while (x < 4 && tab[y][x] == tab[y][x2])
		{
			cnt++;
			x++;
		}
		if (cnt == 2 || cnt == 4)
		{
			tab[y][x2] *= 2;
			(cnt == 2) ? (tab[y][x - 1] = 0) : (0);
			(cnt == 4) ? (tab[y][x2 + 1] = 0) : (0);
		}
	}
	return (tab);
}

static int	**full_case(int **tab, int x, int y, int key)
{
	if (tab[y][x])
	{
		(key == KEY_DOWN) ? (tab = key_down(tab, x, y)) : (0);
		(key == KEY_RIGHT) ? (tab = key_right(tab, x, y)) : (0);
	}
	return (tab);
}

int			**check_keys(int **tab, int key)
{
	int x;
	int y;
	int rand;

	if (key == KEY_DOWN || key == KEY_RIGHT)
	{
		y = 0;
		while (y < ((key == KEY_DOWN) ? (3) : (4)))
		{
			x = 0;
			while (x < ((key == KEY_RIGHT) ? (3) : (4)))
			{
				tab = full_case(tab, x, y, key);
				x++;
			}
			y++;
		}
	}
	else
		tab = check_keys2(tab, key);
	tab = ft_move(tab, key, &rand);
	if (rand == 1)
		(check_rand(tab)) ? (tab = ft_rand(tab)) : (0);
	return (tab);
}
