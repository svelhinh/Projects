/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 14:13:12 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/30 18:43:37 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong_kar_wai.h"

int			**init_tab(void)
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
	srand(time(NULL));
	ft_random(&x, &y, &nb);
	tab[y][x] = nb;
	tab = ft_rand(tab);
	/*i = 0;
	while (i == 0)
	{
		ft_random(&x, &y, &nb);
		if (!tab[y][x])
		{
			tab[y][x] = nb;
			i = 1;
		}
	}*/
	//printf("x = %d\ny = %d\nnb = %d\n\n", x, y, nb);
	/*i = 0;
	int j = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			printf("%d ", tab[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}*/
	return (tab);
}
