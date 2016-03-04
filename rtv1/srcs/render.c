/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 11:21:40 by svelhinh          #+#    #+#             */
/*   Updated: 2016/03/04 16:49:11 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/* Subtract two vectors and return the resulting vector */

t_vector3d	vectorsub(t_vector3d *v1, t_vector3d *v2)
{
	t_vector3d result;

	result.x = v1->x - v2->x;
	result.y = v1->y - v2->y;
	result.z = v1->z - v2->z;
	return (result);
}

/* Multiply two vectors and return the resulting scalar product */

float	vectordot(t_vector3d *v1, t_vector3d *v2)
{
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}

int		sphere(t_ray *r, t_sphere *s, float *t)
{
	float		a;
	float		b;
	float		c;
	float		discr;
	float		t0;
	float		t1;
	int			retval;
	t_vector3d	dist;

	retval = 0;
	a = vectordot(&r->dir, &r->dir);
	dist = vectorsub(&r->start, &s->pos);
	b = 2 * vectordot(&r->dir, &dist);
	c = vectordot(&dist, &dist) - pow(s->radius, 2);
	discr = pow(b, 2) - 4 * a * c;
	if (discr != 0)
	{
		t0 = (-b + sqrt(discr)) / 2;
		t1 = (-b - sqrt(discr)) / 2;
		if (t0 > t1)
			t0 = t1;
		if ((t0 > 0.001) && (t0 < *t))
		{
			*t = t0;
			retval = 1;
		}
	}
	return (retval);
}

void	render(t_rt *rt)
{
	t_sphere	s[3];
	t_ray		r;
	float		t;
	int			i;
	int			currentsphere;
	int			x;
	int			y;

	s[0].pos.x = 2 * SW / 3 + 50;
	s[0].pos.y = SH / 3 - 75;
	s[0].pos.z = 0;
	s[0].radius = 140;
	s[0].color = 0x0;
	s[1].pos.x = SW / 3 - 50;
	s[1].pos.y = SH / 3 - 75;
	s[1].pos.z = 0;
	s[1].radius = 140;
	s[1].color = 0x0;
	s[2].pos.x = SW / 2;
	s[2].pos.y = SH / 2;
	s[2].pos.z = 10;
	s[2].radius = 200;
	s[2].color = 0xEDE1C4;
	y = 0;
	while (y < SH)
	{
		x = 0;
		while (x < SW)
		{
			r.start.x = x;
			r.start.y = y;
			r.start.z = -2000;
			r.dir.x = 0;
			r.dir.y = 0;
			r.dir.z = 1;
			t = 20000;
			currentsphere = -1;
			i = 0;
			while (i < 3)
			{
				if (sphere(&r, &s[i], &t))
					currentsphere = i;
				i++;
			}
			if (currentsphere != -1)
				mlx_pixel_put_to_image(s[currentsphere].color, rt, x, y);
			else
				mlx_pixel_put_to_image(0xffffff, rt, x, y);
			x++;
		}
		y++;
	}
}
