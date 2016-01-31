/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 17:26:31 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/31 19:15:59 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong_kar_wai.h"

void	ft_random(int *x, int *y, int *nb)
{
	*nb = rand() % 5;
	*x = rand() % 4;
	*y = rand() % 4;
	*nb = (*nb >= 0 && *nb <= 3) ? (2) : (4);
}

int		**ft_rand(int **tab)
{
	int i;
	int nb;
	int x;
	int y;

	x = 0;
	y = 0;
	nb = 0;
	i = 0;
	while (i == 0)
	{
		ft_random(&x, &y, &nb);
		if (!tab[y][x])
		{
			tab[y][x] = nb;
			i = 1;
		}
	}
	return (tab);
}
