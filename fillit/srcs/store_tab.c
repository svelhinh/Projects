/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 17:39:38 by svelhinh          #+#    #+#             */
/*   Updated: 2015/12/18 17:55:07 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void		ft_tab_store(char **tab, t_coord **coord)
{
	int		x;
	int		y;
	int		blk;

	y = 0;
	blk = 0;
	while (tab[y])
	{
		x = 0;
		while (tab[x])
		{
			if ((*coord)->x[blk] == x && (*coord)->y[blk] == y)
			{
				tab[y][x] = (*coord)->c;
				blk++;
			}
			x++;
		}
		printf("%s\n", tab[y]);
		y++;
	}
	printf("\n");
}
