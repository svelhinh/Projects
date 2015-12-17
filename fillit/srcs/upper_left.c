/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upper_left.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 11:11:09 by svelhinh          #+#    #+#             */
/*   Updated: 2015/12/17 13:30:31 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int			ft_xmin(t_coord *coord)
{
	int xmin;
	int blk;

	xmin = 105;
	blk = 0;
	while (blk != 4)
	{
		if (coord->x[blk] < xmin)
			xmin = coord->x[blk];
		blk++;
	}
	return (xmin);
}

int			ft_ymin(t_coord *coord)
{
	int ymin;
	int blk;

	ymin = 105;
	blk = 0;
	while (blk != 4)
	{
		if (coord->y[blk] < ymin)
			ymin = coord->y[blk];
		blk++;
	}
	return (ymin);
}

void	ft_placex(t_coord **first, int x)
{
	int xmin;
	int blk;

	blk = 0;
	xmin = ft_xmin(*first);
	while (blk != 4)
	{
		(*first)->x[blk] = (*first)->x[blk] - xmin + x;
		printf("x[%d] = %d\n\n", blk, (*first)->x[blk]);
		blk++;
	}
}

void	ft_placey(t_coord **first, int x)
{
	int xmin;
	int blk;

	blk = 0;
	xmin = ft_xmin(*first);
	while (blk != 4)
	{
		(*first)->x[blk] = (*first)->x[blk] - xmin + x;
		printf("x[%d] = %d\n\n", blk, (*first)->x[blk]);
		blk++;
	}
}

char	*ft_upper_left(t_coord **first, int x, int y)
{
	(void)y;
	ft_placex(first, x);
	return ("yolo");
}
