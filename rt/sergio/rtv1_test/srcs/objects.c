/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 15:12:19 by svelhinh          #+#    #+#             */
/*   Updated: 2016/04/22 16:45:03 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		sphere(t_ray *r, t_sphere *s, double *t)
{
	double	a;
	double	b;
	double	c;
	double	disc;
	double	t0;
	double	t1;
	int		retval;

	a = pow(r->dir.x, 2) + pow(r->dir.y, 2) + pow(r->dir.z, 2);
	b = 2 * (r->dir.x * (r->start.x - s->pos.x) + r->dir.y * (r->start.y - s->pos.y) + r->dir.z * (r->start.z - s->pos.z));
	c = (pow(r->start.x - s->pos.x, 2) + pow(r->start.y - s->pos.y, 2) + pow(r->start.z - s->pos.z, 2)) - pow(s->radius, 2);
	disc = pow(b, 2) - 4 * a * c;
	if (disc < 0)
		return (0);
	t0 = (-b - sqrt(disc)) / (2 * a);
	t1 = (-b + sqrt(disc)) / (2 * a);
	retval = 0;
	if (t0 > 0.01 && t0 < *t)
	{
		*t = t0;
		retval = 1;
	}
	if (t1 > 0.01 && t1 < *t)
		*t = t1;
	return (retval);
}

int		plane(t_ray *r, t_plane *p, double *t)
{
	double		tmp;

	tmp = -(p->norm.x * r->start.x + p->norm.y * r->start.y + p->norm.z *
		r->start.z + p->height) / (p->norm.x * r->dir.x + p->norm.y * r->dir.y +
			p->norm.z * r->dir.z);
	if (tmp < *t && tmp > 0.01)
	{
		*t = tmp;
		return (1);
	}
	return (0);
}

int		cylinder(t_ray *r, t_cylinder *cy, double *t)
{
	double		a;
	double		b;
	double		c;
	double		disc;
	double		t0;
	double		t1;
	int			retval;

	a = pow(r->dir.x, 2) + pow(r->dir.z, 2);
	b = 2 * (r->dir.x * (r->start.x - cy->pos.x) + r->dir.z * (r->start.z - cy->pos.z));
	c = pow(r->start.x - cy->pos.x, 2) + pow(r->start.z - cy->pos.z, 2) - pow(cy->radius, 2);

	disc = pow(b, 2) - 4 * a * c;
	if (disc < 0)
		return (0);
	t0 = (-b - sqrt(disc)) / (2 * a);
	t1 = (-b + sqrt(disc)) / (2 * a);
	retval = 0;
	if (t0 > 0.01 && t0 < *t)
	{
		*t = t0;
		retval = 1;
	}
	if (t1 > 0.01 && t1 < *t)
		*t = t1;
	return (retval);
}

int		cone(t_ray *r, t_cone *co, double *t)
{
	double		t0;
	double		t1;
	double		a;
	double		b;
	double		c;
	double		disc;
	int			retval;

	a = pow(r->dir.x, 2) - pow(r->dir.y, 2) + pow(r->dir.z, 2);
	b = 2 * (r->dir.x * (r->start.x - co->pos.x) - r->dir.y * (r->start.y - co->pos.y) + r->dir.z * (r->start.z - co->pos.z));
	c = (pow(r->start.x - co->pos.x, 2) - pow(r->start.y - co->pos.y, 2) + pow(r->start.z - co->pos.z, 2));
	disc = pow(b, 2) - 4 * a * c;
	if (disc < 0)
		return (0);
	t0 = (-b - sqrt(disc)) / (2 * a);
	t1 = (-b + sqrt(disc)) / (2 * a);
	retval = 0;
	if (t0 > 0.01 && t0 < *t)
	{
		*t = t0;
		retval = 1;
	}
	if (t1 > 0.01 && t1 < *t)
		*t = t1;
	return (retval);
}
