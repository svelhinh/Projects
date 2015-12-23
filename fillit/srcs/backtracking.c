/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 17:03:51 by svelhinh          #+#    #+#             */
/*   Updated: 2015/12/23 13:46:20 by stoussay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_delete_blk(char **tab, t_coord *coord, int tablen)
{
	int x;
	int y;

	y = 0;
	while (y < tablen)
	{
		x = 0;
		while (x < tablen)
		{
			if (tab[y][x] == coord->c)
				tab[y][x] = '.';
			x++;
		}
		y++;
	}
	return (tab);
}

char **ft_backtracking(char **tab, t_coord *coord, int tablen)
{
	int x;
	int y;
	char**tmp;

	if (!coord)
		return (tab);
	tmp = NULL;
	y = 0;
	while (y < tablen)
	{
		x = 0;
		while (x < tablen)
		{
			coord = *ft_move(&coord, x, y);
			if (ft_check(tab, &coord, tablen))
				tmp = ft_backtracking(ft_tab_store(tab, &coord, tablen), coord->next, tablen);
			if (tmp)
				return (tmp);
			tab = ft_delete_blk(tab, coord, tablen);
			++x;
		}
		++y;
	}
	return (NULL);
}

char**solve(t_coord *coord, int tablen)
{
	char **tab;

	tab = NULL;
	while (!tab)
	{
		tab = ft_empty(tab, tablen);
		tab = ft_backtracking(tab, coord, tablen);
		tablen++;
	}
	return (tab);
}
