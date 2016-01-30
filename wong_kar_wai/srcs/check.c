/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 18:48:04 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/30 19:03:02 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong_kar_wai.h"

int		check_rand(int **tab)
{
	int x;
	int y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (tab[y][x] == 0)
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int		check_tab(int **tab)
{
	int x;
	int y;

	y = 0;
	if (!check_rand(tab))
	{
		while (y < 4)
		{
			x = 0;
			while (x < 4)
			{
				if (x != 3)
					if (tab[y][x + 1] == tab[y][x])
						return (0);
				if (y != 3)
					if (tab[y + 1][x] == tab[y][x])
						return (0);
				x++;
			}
			y++;
		}
		return (1);
	}
	return (0);
}
