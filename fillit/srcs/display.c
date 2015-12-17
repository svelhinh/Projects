/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 17:39:38 by svelhinh          #+#    #+#             */
/*   Updated: 2015/12/17 18:02:06 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_tab_store(char **tab, t_coord **coord)
{
	int x;
	int y;
	int blk;

	y = 0;
	blk = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if ((*coord)->x[blk] == x && (*coord)->y[blk] == y)
				tab[y][x] = (*coord)->c;
			else
				tab[y][x] = '.';
			x++;
		}
		y++;
	}
	return (tab);
}

void	ft_display(t_coord **coord)
{
	int i;
	int x;
	int y;
	int blk;

	i = 0;
	y = 0;
	blk = 0;
	while (i < 16)
	{
		if (i % 4 == 0 && i != 0)
		{
			x = 0;
			y++;
			ft_putchar('\n');
		}
		if (x == (*coord)->x[blk] && y == (*coord)->y[blk])
		{
			ft_putchar((*coord)->c);
			blk++;
		}
		else
			ft_putchar('.');
		i++;
		x++;
	}
	ft_putstr("\n\n");
}
