/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 17:03:51 by svelhinh          #+#    #+#             */
/*   Updated: 2015/12/19 12:49:05 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check(t_coord *coord, int tablen)
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

void	ft_backtracking(t_coord **first)
{
	t_coord *coord;
	t_varf v;
	char **tab;
	int tablen;

	tab = NULL;
	tablen = 2;
	v.x = 0;
	v.y = 0;
	coord = *first;
	tab = ft_empty(tab, tablen);
	while (coord)
	{
		coord = ft_move(&coord, v.x, v.y);
		if (ft_check(coord, tablen))
			tab = ft_display(&coord, tab, tablen);
		else
		{
			if (coord == *first)
			{
				tablen++;
				tab = ft_empty(tab, tablen);
			}
		}
	}
}
