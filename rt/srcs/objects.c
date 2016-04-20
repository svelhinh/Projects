/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 15:12:19 by svelhinh          #+#    #+#             */
/*   Updated: 2016/04/20 15:12:21 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		sphere(t_ray *r, t_sphere *s)
{
	float	a;
	float	b;
	float	c;
	float	disc;

	a = pow(r->dir.x, 2) + pow(r->dir.y, 2) + pow(r->dir.z, 2);
	b = 2 * (r->dir.x * (r->start.x - s->pos.x) + r->dir.y * (r->start.y - s->pos.y) + r->dir.z * (r->start.z - s->pos.z));
	c = (pow(r->start.x - s->pos.x, 2) + pow(r->start.y - s->pos.y, 2) + pow(r->start.z - s->pos.z, 2)) - pow(s->radius, 2);
	disc = pow(b, 2) - 4 * a * c;
	if (disc < 0)
		return (0);
	return (1);
}