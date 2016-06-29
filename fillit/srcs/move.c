/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upper_left.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 11:11:09 by svelhinh          #+#    #+#             */
/*   Updated: 2015/12/23 17:36:58 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_xmin(t_coord *coord)
{
	int xmin;
	int blk;

	xmin = 200;
	blk = 0;
	while (blk != 4)
	{
		if (coord->x[blk] < xmin)
			xmin = coord->x[blk];
		blk++;
	}
	return (xmin);
}

static void	ft_placex(t_coord *first, int x)
{
	int xmin;
	int blk;

	blk = 0;
	xmin = ft_xmin(first);
	while (blk != 4)
	{
		first->x[blk] = first->x[blk] - xmin + x;
		blk++;
	}
}

static int	ft_ymin(t_coord *coord)
{
	int ymin;
	int blk;

	ymin = 200;
	blk = 0;
	while (blk != 4)
	{
		if (coord->y[blk] < ymin)
			ymin = coord->y[blk];
		blk++;
	}
	return (ymin);
}

static void	ft_placey(t_coord *first, int y)
{
	int ymin;
	int blk;

	blk = 0;
	ymin = ft_ymin(first);
	while (blk != 4)
	{
		first->y[blk] = first->y[blk] - ymin + y;
		blk++;
	}
}

t_coord		*ft_move(t_coord *first, int x, int y)
{
	ft_placex(first, x);
	ft_placey(first, y);
	return (first);
}
