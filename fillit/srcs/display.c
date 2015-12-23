/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 17:39:38 by svelhinh          #+#    #+#             */
/*   Updated: 2015/12/23 13:46:35 by stoussay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
int			ft_check(char **tab, t_coord **coord, int tablen)
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
			if ((*coord)->x[blk] == x && (*coord)->y[blk] == y
					&& tab[y][x] != '.')
				return (0);
			else if ((*coord)->x[blk] == x && (*coord)->y[blk] == y)
				blk++;
			x++;
		}
		y++;
	}
	if (blk < 4)
		return (0);
		return (1);
}

char		**ft_tab_store(char **tab, t_coord **coord, int tablen)
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
			if ((*coord)->x[blk] == x && (*coord)->y[blk] == y)
			{
				tab[y][x] = (*coord)->c;
				blk++;
			}
			x++;
		}
		tab[y][x] = '\0';
		y++;
	}
	tab[y] = NULL;
	return (tab);
}
