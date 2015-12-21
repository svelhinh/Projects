/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 17:03:51 by svelhinh          #+#    #+#             */
/*   Updated: 2015/12/21 19:09:09 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

/*int		ft_check_tab(char **tab, t_coord *coord, int tablen)
{
	int x;
	int y;

	y = 0;
	x = 0;
	while (!ft_check(tab, &coord, tablen) && y < tablen)
	{
		if (x == tablen)
		{
			x = 0;
			y++;
		}
		else
			x++;
		coord = *ft_move(&coord, x, y);
	}
	if (!ft_check(tab, &coord, tablen))
		return (0);
	if (coord->c == 'A')
		coord = *ft_move(&coord, 0, 0);
	return (1);
}

char	**ft_backtracking(char **tab, t_coord *coord, int tablen)
{
	if (coord)
	{
		//printf("\ncoord c = %c\n", coord->c);
		if (ft_check_tab(tab, coord, tablen))
		{
			tab = ft_tab_store(tab, &coord, tablen);
			coord = coord->next;
		}
		else if (coord->c == 'A')
		{
			tablen++;
			tab = ft_empty(tab, tablen);
		}
		ft_backtracking(tab, coord, tablen);
	}
	return (tab);
}*/

void	ft_move_blk(t_coord *coord)
{
	int x;
	int y;
	char **tab;
	int tablen;
	
	tablen = 2;
	y = tablen;
	tab = NULL;
	while (y >= tablen)
	{
		x = 0;
		y = 0;
		tab = ft_empty(tab, tablen);
		/*while (x < 4)
		{
			printf("avant :\n\ncoord x = %d\ncoord y = %d\n\n", coord->x[x], coord->y[x]);
			x++;
		}
		x = 0;*/
		coord = ft_move(coord, x, y);
		/*while (x < 4)
		{
			printf("apres :\n\ncoord x = %d\ncoord y = %d\n\n", coord->x[x], coord->y[x]);
			x++;
		}
		x = 0;*/
		/*printf("tab = %s\ntablen = %d\n\n", tab[0], tablen);
		printf("tab = %s\ntablen = %d\n\n", tab[1], tablen);
		printf("tab = %s\ntablen = %d\n\n", tab[2], tablen);
		printf("tab = %s\ntablen = %d\n\n", tab[3], tablen);*/
		printf("ft_check = %d\n\n", ft_check(tab, coord, tablen));
		while (!ft_check(tab, coord, tablen) && y <= tablen)
		{
			if (x == tablen)
			{
				x = 0;
				y++;
			}
			else
				x++;
			coord = ft_move(coord, x, y);
		}
		if (y >= tablen)		// Pas sur
			tablen++;
	}
	tab = ft_tab_store(tab, coord, tablen);
}
