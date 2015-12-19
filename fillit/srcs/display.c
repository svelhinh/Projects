/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 17:39:38 by svelhinh          #+#    #+#             */
/*   Updated: 2015/12/19 19:11:48 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int			ft_check_tab(char **tab, t_coord **coord, int tablen)
{
	int		x;
	int		y;
	int		blk;

	y = 0;
	blk = 0;
	while (y < tablen)
	{
		x = 0;
		while (x < tablen)
		{
			if (((*coord)->x[blk] == x && (*coord)->y[blk] == y
					&& tab[y][x] != '.') || ((*coord)->x[blk] > tablen - 1
					|| (*coord)->y[blk] > tablen - 1))
				return (0);
			else if ((*coord)->x[blk] == x && (*coord)->y[blk] == y
					&& tab[y][x] == '.')
				blk++;
			x++;
		}
		y++;
	}
	return (1);
}

char	**ft_tab_store(char **tab, t_coord *coord, int tablen)
{
	int x;
	int y;
	int blk;

	y = 0;
	blk = 0;
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
