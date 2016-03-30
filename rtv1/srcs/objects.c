/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 10:43:50 by svelhinh          #+#    #+#             */
/*   Updated: 2016/03/30 12:27:41 by svelhinh         ###   ########.fr       */
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
	t_vector3d	norm;
	float		tmp;

	p->rot.x = 0.3;
	p->rot.y = 0;
	p->rot.z = 0;
	norm = rotations(p->norm, p->rot.x, p->rot.y, p->rot.z);
	tmp = -(p->height + norm.x * r->start.x + norm.y * r->start.y + norm.z * r->start.z)
		/ (norm.x * r->dir.x + norm.y * r->dir.y + norm.z * r->dir.z);
	if (tmp < *t && tmp > 0.01)
	{
		*t = tmp;
		return (1);
	}
	return (0);
}

/*
** tab[0] = t0, tab[1] = t1, tab[2] = xyz
*/

int		cylinder(t_ray *r, t_cylinder *cy, float *t)
{
	t_vector3d	dist;
	float		tab[3];
	float		b;
	float		d;
	int			retval;

	//cy->rot.x = 0;
	//cy->rot.y = 0;
	//cy->rot.z = 0;
	tab[2] = 0;
	if (cy->pos.x == 0)
		tab[2] = 1;
	else if (cy->pos.y == 0)
		tab[2] = 2;
	else if (cy->pos.z == 0)
		tab[2] = 3;
	dist = vectorsub(&cy->pos, &r->start, tab[2]);
	//dist = rotations(dist, cy->rot.x, cy->rot.y, cy->rot.z);
	b = vectordot(&r->dir, &dist, tab[2]);
	d = pow(b, 2) - vectordot(&dist, &dist, tab[2]) + pow(cy->radius, 2);
	if (d < 0)
		return (0);
	tab[0] = b - sqrt(d);
	tab[1] = b + sqrt(d);
	retval = 0;
	if (tab[0] > 0.1 && tab[0] < *t && (retval = 1))
		*t = tab[0];
	*t = (tab[1] > 0.1 && tab[1] < *t) ? (tab[1]) : (*t);
	return (retval);
}

/*
** tab[0] = t0, tab[1] = t1
*/

int		cone(t_ray *r, t_cone *co, float *t)
{
	t_vector3d	norm;
	float		tab[2];
	float		b;
	float		d;
	int			retval;

	co->rot.x = 0;
	co->rot.y = 0;
	co->rot.z = 0;
	norm = vectorsub(&co->pos, &r->start, 0);
	norm = rotations(norm, co->rot.x, co->rot.y, co->rot.z);
	b = vectordot(&r->dir, &norm, 'y');
	d = pow(b, 2) - vectordot(&norm, &norm, 'y') + pow(co->radius, 2);
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
