/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 10:43:50 by svelhinh          #+#    #+#             */
/*   Updated: 2016/03/24 13:18:09 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*
 ** tab[0] = t0, tab[1] = t1
*/

int		sphere(t_ray *r, t_sphere *s, float *t)
{
	t_vector3d	dist;
	float		tab[2];
	float		b;
	float		d;
	int			retval;

	dist = vectorsub(&s->pos, &r->start, 0);
	b = vectordot(&r->dir, &dist, 0);
	d = pow(b, 2) - vectordot(&dist, &dist, 0) + pow(s->radius, 2);
	if (d < 0)
		return (0);
	tab[0] = b - sqrt(d);
	tab[1] = b + sqrt(d);
	retval = 0;
	if (tab[0] > 0.1 && tab[0] < *t)
	{
		*t = tab[0];
		retval = 1;
	}
	if (tab[1] > 0.1 && tab[1] < *t)
	{
		*t = tab[1];
		retval = 0;
	}
	return (retval);
}

/*
 ** e[0] = a, e[1] = b, e[2] = c
*/

int		plane(t_ray *r, t_plane *p, float *t)
{
	float	tmp;
	float	A;
	float	B;
	float	C;
	float	D;

	A = p->pos.x;
	B = p->pos.y;
	C = p->pos.z;
	D = 0;
	tmp = -(D + A * r->start.x + B * r->start.y + C * r->start.z) / (A * r->dir.x + B * r->dir.y + C * r->dir.z);
	if (tmp < *t && tmp > 0.01)
	{
		*t = tmp;
		return (1);
	}
	return (0);
	/*t_vector3d	vec;
	float		e[3];
	float		tmp;

	vec = vectorsub(&r->start, &p->pos, 0);
	e[0] = p->pos.x;
	e[1] = p->pos.y;
	e[2] = p->pos.z;
	tmp = -((e[0] * vec.x + e[1] * vec.y + e[2] * vec.z)
			/ (e[0] * r->dir.x + e[1] * r->dir.y + e[2] * r->dir.z));
	if (tmp < *t && tmp > 0.01)
	{
		*t = tmp;
		return (1);
	}
	return (0);*/
}

/*
 ** tab[0] = t0, tab[1] = t1, tab[2] = xyz
*/

int		cylinder(t_ray *r, t_cylinder *c, float *t)
{
	t_vector3d	dist;
	float		tab[3];
	float		b;
	float		d;
	int			retval;

	tab[2] = 0;
	if (c->pos.x == 0)
		tab[2] = 1;
	else if (c->pos.y == 0)
		tab[2] = 2;
	else if (c->pos.z == 0)
		tab[2] = 3;
	dist = vectorsub(&c->pos, &r->start, tab[2]);
	b = vectordot(&r->dir, &dist, tab[2]);
	d = pow(b, 2) - vectordot(&dist, &dist, tab[2]) + pow(c->radius, 2);
	if (d < 0)
		return (0);
	tab[0] = b - sqrt(d);
	tab[1] = b + sqrt(d);
	retval = 0;
	if (tab[0] > 0.1 && tab[0] < *t)
	{
		*t = tab[0];
		retval = 1;
	}
	if (tab[1] > 0.1 && tab[1] < *t)
	{
		*t = tab[1];
		retval = 0;
	}
	return (retval);
}

int		cone(t_ray *r, t_cone *co, float *t)
{
	t_vector3d	dist;
	float		tab[2];
	float		b;
	float		d;
	int			retval;

	dist = vectorsub(&co->pos, &r->start, 0);
	b = vectordot(&r->dir, &dist, co->axis);
	d = pow(b, 2) - vectordot(&dist, &dist, co->axis) + pow(co->radius, 2);
	if (d < 0)
		return (0);
	tab[0] = b - sqrt(d);
	tab[1] = b + sqrt(d);
	retval = 0;
	if (tab[0] > 0.1 && tab[0] < *t)
	{
		*t = tab[0];
		retval = 1;
	}
	if (tab[1] > 0.1 && tab[1] < *t)
	{
		*t = tab[1];
		retval = 0;
	}
	return (retval);
}
