/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 17:03:51 by svelhinh          #+#    #+#             */
/*   Updated: 2015/12/22 15:51:47 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		ft_check_tab(char **tab, t_coord *coord, int tablen)
{
	int x;
	int y;

	y = 0;
	x = 0;
	coord = *ft_move(&coord, x, y);
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
	return (1);
}

/*char	**ft_resize_tab(t_coord **first, int tablen)
  {
  t_coord *coord;
  t_varf v;
  char **tab;

  tab = NULL;
  v.x = 0;
  v.y = 0;
  coord = *first;
  tab = ft_empty(tab, tablen);
  coord = *ft_move(&coord, v.x, v.y);
  if (!ft_check_tab(tab, coord, tablen, v.x, v.y))
  ft_resize_tab(first, tablen + 1);
  return (tab);
  }

  char		**ft_backtracking(char **tab, t_coord **coord, int tablen)
  {
//if (*coord == NULL)
//	return (tab);
if (ft_check_tab(tab, *coord, tablen, 0, 0))
{
tab = ft_tab_store(tab, coord, tablen);
 *coord = (*coord)->next;
 return (ft_backtracking(tab, &(*coord), tablen));
 }
 else
 {
 tablen++;
 tab = ft_resize_tab(coord, tablen);
 ft_backtracking(tab, &(*coord), tablen);
 }
 return (NULL);
 }*/

/*char	**ft_delete_tab(char **tab, char c, int tablen)
  {
  int x;
  int y;

  y = 0;
  while (y < tablen)
  {
  x= 0;
  while (x < tablen)
  {
  if (tab[y][x] == c)
  tab[y][x] = '.';
  x++;
  }
  y++;
  }
  return (tab);
  }*/

void	ft_resize_tab(t_coord *coord, int tablen, char **tab)
{
	while (!tab)
	{
		while (!ft_check_tab(tab, coord, tablen))
		{
			tab = ft_empty(tab, tablen);
			tablen++;
		}
		tab = ft_backtracking(tab, coord, tablen);
	}
}

char		**ft_backtracking(char **tab, t_coord *coord, int tablen)
{
	char **tmp;

	tmp = NULL;
	if (ft_check_tab(tab, coord, tablen))
	{
		printf("\n\n");
		tmp = ft_backtracking(ft_tab_store(tab, &coord, tablen), coord->next, tablen);
	}
	if (!tmp)
		return (tmp);
	return (NULL);
}
