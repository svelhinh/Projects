/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 10:53:35 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/20 17:26:13 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	mand_jul_illu(t_fract *e)
{
	if (!ft_strcmp(e->fract, "mandelbrot"))
	{
		e->x1 = -2.6;
		e->x2 = 0.8;
		e->y1 = -1.2;
		e->y2 = 1.2;
		e->zoom = 300;
	}
	if (!ft_strcmp(e->fract, "julia"))
	{
		e->x1 = -2.8;
		e->x2 = 1.5;
		e->y1 = -1.9;
		e->y2 = 1.5;
		e->zoom = 175;
	}
	if (!ft_strcmp(e->fract, "illuminati"))
	{
		e->x1 = -2.5;
		e->x2 = 0.8;
		e->y1 = -1.8;
		e->y2 = 1.2;
		e->zoom = 200;
	}
}

static void	water_salad(t_fract *e)
{
	if (!ft_strcmp(e->fract, "water drop"))
	{
		e->x1 = -1.5;
		e->x2 = 0.8;
		e->y1 = -1.9;
		e->y2 = 1.2;
		e->zoom = 175;
	}
	if (!ft_strcmp(e->fract, "salad"))
	{
		e->x1 = -500;
		e->x2 = 0.8;
		e->y1 = -350;
		e->y2 = 1.2;
		e->zoom = 1;
	}
}

void		var_init(t_fract *e)
{
	mand_jul_illu(e);
	water_salad(e);
	if (!ft_strcmp(e->fract, "eye"))
	{
		e->x1 = -2.7;
		e->x2 = 0.8;
		e->y1 = -1.9;
		e->y2 = 1.2;
		e->zoom = 175;
	}
	if (!ft_strcmp(e->fract, "star"))
	{
		e->x1 = -2.7;
		e->x2 = 0.8;
		e->y1 = -1.9;
		e->y2 = 1.2;
		e->zoom = 175;
	}
	e->coeffx = 0;
	e->coeffx = 0;
	e->coeffy = 0;
	e->y = 0;
	e->i_max = 50;
	e->i_max_base = 50;
}
