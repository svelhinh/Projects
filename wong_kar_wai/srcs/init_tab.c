/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 14:13:12 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/31 10:20:53 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong_kar_wai.h"

int			**init_tab(int j)
{
	int x;
	int y;
	int nb;
	int **tab;
	int i;

	x = 0;
	y = 0;
	nb = 0;
	i = 0;
	if (!(tab = (int **)malloc(sizeof(int *) * 4)))
		return (0);
	while (i < 4)
		tab[i++] = ft_tabnew(4);
	if (j)
	{
		srand(time(NULL));
		ft_random(&x, &y, &nb);
		tab[y][x] = nb;
		tab = ft_rand(tab);
	}
	/*i = 0;
	int w = 0;
	while (i < 4)
	{
		w = 0;
		while (w < 4)
		{
			printf("%d ", tab[i][w]);
			w++;
		}
		printf("\n");
		i++;
	}*/
	return (tab);
}
