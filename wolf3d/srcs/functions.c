/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/23 11:29:30 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/27 18:14:29 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_swap(float *a, float *b)
{
	float c;

	c = *a;
	*a = *b;
	*b = c;
}

static void	start_position(t_ray *r)
{
	if (ft_strstr(r->lvl, "lvl0"))
	{
		r->posx = 30.5;
		r->posy = 5;
	}
}

void		init_var(t_ray *r)
{
	start_position(r);
	r->dirx = -1;
	r->diry = 0;
	r->planex = 0;
	r->planey = 0.66;
}
