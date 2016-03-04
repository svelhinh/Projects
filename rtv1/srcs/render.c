/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 11:21:40 by svelhinh          #+#    #+#             */
/*   Updated: 2016/03/04 17:59:16 by svelhinh         ###   ########.fr       */
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

int		plane(t_ray *r, t_plane *p, float *t)
{
	float	x;
	float	y;
	float	z;
	float	a;
	float	b;
	float	c;
	float	tmp;

	x = r->start.x - p->pos.x;
	y = r->start.y - p->pos.y;
	z = r->start.z - p->pos.z;
	a = p->pos.x;
	b = p->pos.y;
	c = p->pos.z;
	tmp = -((a * x + b * y + c * z) / (a * r->dir.x + b * r->dir.y + c * r->dir.z));
	if (tmp < *t && tmp > 0.001)
	{
		*t = tmp;
		return (1);
	}
	return (0);
}

void	render(t_rt *rt)
{
	t_sphere	s[3];
	t_plane		p[2];
	t_ray		r;
	char		*object;
	float		t;
	int			i;
	int			currentobject;
	int			x;
	int			y;

	s[0].pos.x = 2 * SW / 3 + 50;
	s[0].pos.y = SH / 3 - 75;
	s[0].pos.z = 0;
	s[0].radius = 140;
	s[0].color = 0x987b12;
	s[1].pos.x = SW / 3 - 50;
	s[1].pos.y = SH / 3 - 75;
	s[1].pos.z = 0;
	s[1].radius = 140;
	s[1].color = 0x762803;
	s[2].pos.x = SW / 2;
	s[2].pos.y = SH / 2;
	s[2].pos.z = 10;
	s[2].radius = 200;
	s[2].color = 0x98;
	p[0].pos.x = 0;
	p[0].pos.y = 0;
	p[0].pos.z = 200;
	p[0].color = 0x0;
	p[1].pos.x = 100;
	p[1].pos.y = 300;
	p[1].pos.z = 200;
	p[1].color = 0xffff;
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
			currentobject = -1;
			i = 0;
			while (i < 3)
			{
				if (sphere(&r, &s[i], &t) && i < 3)
				{
					currentobject = i;
					if (!ft_strstr(object, "sphere"))
						object = ft_strdup("sphere");
				}
				if (plane(&r, &p[i], &t) && i < 2)
				{
					currentobject = i;
					if (!ft_strstr(object, "plane"))
						object = ft_strdup("plane");
				}
				i++;
			}
			if (currentobject != -1)
			{
				if (ft_strstr("sphere", object))
					mlx_pixel_put_to_image(s[currentobject].color, rt, x, y);
				else if (ft_strstr("plane", object))
					mlx_pixel_put_to_image(p[currentobject].color, rt, x, y);
			}
			else
				mlx_pixel_put_to_image(0x0, rt, x, y);
			x++;
		}
		y++;
	}
}
