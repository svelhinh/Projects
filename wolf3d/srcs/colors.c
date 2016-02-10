/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 11:56:11 by svelhinh          #+#    #+#             */
/*   Updated: 2016/02/10 12:00:50 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_floor(t_ray *r, t_coords *c)
{
	if (r->nb_lvl == 2)
		c->color = (r->texture[4][r->w * r->ftexy + r->ftexx] >> 1) & 8355711;
	else if (r->nb_lvl == 1)
		c->color = (r->texture[6][r->w * r->ftexy + r->ftexx] >> 1) & 8355711;
	else
		c->color = (r->texture[0][r->w * r->ftexy + r->ftexx] >> 1) & 8355711;
}

void	ft_sky(t_ray *r, t_coords *c)
{
	if (r->nb_lvl == 2)
		c->color = CSKY;
	else if (r->nb_lvl == 1)
		c->color = r->texture[6][r->w * r->ftexy + r->ftexx];
	else
		c->color = r->texture[0][r->w * r->ftexy + r->ftexx];
}
