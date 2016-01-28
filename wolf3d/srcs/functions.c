/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/23 11:29:30 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/28 15:54:21 by svelhinh         ###   ########.fr       */
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

void		init_var(t_ray *r)
{
	if (ft_strstr(r->lvl, "lvl0"))
	{
		r->posx = 30.5;
		r->posy = 5;
	}
	r->time = 0;
	r->oldtime = 0;
	r->dirx = -1;
	r->diry = 0;
	r->planex = 0;
	r->planey = 0.66;
}
