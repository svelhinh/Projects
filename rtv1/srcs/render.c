/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 11:21:40 by svelhinh          #+#    #+#             */
/*   Updated: 2016/03/10 16:56:15 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int		sphere(t_ray *r, t_sphere *s, float *t)
{
	t_vector3d	dist;
	float		b;
	float		d;
	float		t0;
	float		t1;
	int			retval;

	dist = vectorsub(&s->pos, &r->start);
	b = vectordot(&r->dir, &dist);
	d = pow(b, 2) - vectordot(&dist, &dist) + pow(s->radius, 2);
	if (d < 0)
		return (0);
	t0 = b - sqrt(d);
	t1 = b + sqrt(d);
	retval = 0;
	if (t0 > 0.1 && t0 < *t)
	{
		*t = t0;
		retval = 1;
	}
	if (t1 > 0.1 && t1 < *t)
	{
		*t = t1;
		retval = 0;
	}
	return (retval);
}

static int		plane(t_ray *r, t_plane *p, float *t)
{
	float	x;
	float	y;
	float	z;
	float	e[3];	/*e[0] = a, e[1] = b, e[2] = c*/
	float	tmp;

	x = r->start.x - p->pos.x;
	y = r->start.y - p->pos.y;
	z = r->start.z - p->pos.z;
	e[0] = p->pos.x;
	e[1] = p->pos.y;
	e[2] = p->pos.z;
	tmp = -((e[0] * x + e[1] * y + e[2] * z)
			/ (e[0] * r->dir.x + e[1] * r->dir.y + e[2] * r->dir.z));
	if (tmp < *t && tmp > 0.01)
	{
		*t = tmp;
		return (1);
	}
	return (0);
}

void		render(t_rt *rt)
{
	/*t_sphere	s[7];
	t_plane		p[1];*/
	char		*object;
	float		t;
	int			i;
	int			currentobject;
	int			x;
	int			y;

	/*s[0].pos.x = 100;
	s[0].pos.y = 100;
	s[0].pos.z = 0;
	s[0].radius = 10;
	s[0].color = 0xec1d00;
	s[6].pos.x = 225;
	s[6].pos.y = 100;
	s[6].pos.z = 0;
	s[6].radius = 20;
	s[6].color = 0x5D5A55;
	s[2].pos.x = 100;
	s[2].pos.y = 300;
	s[2].pos.z = 0;
	s[2].radius = 30;
	s[2].color = 0xD89140;
	s[3].pos.x = 100;
	s[3].pos.y = 400;
	s[3].pos.z = 0;
	s[3].radius = 40;
	s[3].color = 0x418BED;
	s[4].pos.x = 100;
	s[4].pos.y = 500;
	s[4].pos.z = 0;
	s[4].radius = 50;
	s[4].color = 0xE95959;
	s[5].pos.x = 100;
	s[5].pos.y = 400;
	s[5].pos.z = 0;
	s[5].radius = 60;
	s[5].color = 0xE66832;
	s[1].pos.x = 425;
	s[1].pos.y = 100;
	s[1].pos.z = 0;
	s[1].radius = 70;
	s[1].color = 0xD5C07B;
	p[0].pos.x = 100;
	p[0].pos.y = 650;
	p[0].pos.z = 3;
	p[0].color = 0x757063;*/
	y = 0;
	//printf("nbs = %d\npos.x = %f\npos.y = %f\npos.z = %f\nradius = %f\ncolor = %d\n\n", rt->nbs, rt->s[6].pos.x, rt->s[6].pos.y, rt->s[6].pos.z, rt->s[6].radius, rt->s[6].color);
	while (y < SH)
	{
		x = 0;
		while (x < SW)
		{
			rt->r.start.x = (float)x + rt->campos.x;
			rt->r.start.y = (float)y + rt->campos.y;
			rt->r.start.z = -10000 + rt->campos.z;
			t = 20000;
			currentobject = -1;
			i = 0;
			object = NULL;
			while (i < rt->nbs)			// Ne pas oublier de trouver le i max
			{
				if (i < rt->nbs && sphere(&rt->r, &rt->s[i], &t))
				{
					currentobject = i;
					if (!ft_strstr(object, "sphere"))
					{
						if (object)
							ft_strdel(&object);
						object = ft_strdup("sphere");
					}
				}
				if (i < rt->nbp && plane(&rt->r, &rt->p[i], &t))
				{
					currentobject = i;
					if (!ft_strstr(object, "plane"))
					{
						if (object)
							ft_strdel(&object);
						object = ft_strdup("plane");
					}
				}
				i++;
			}
			if (currentobject != -1)
			{
				if (ft_strstr("sphere", object))
					mlx_pixel_put_to_image(rt->s[currentobject].color, rt, x, y);
				else if (ft_strstr("plane", object))
					mlx_pixel_put_to_image(rt->p[currentobject].color, rt, x, y);
				if (object)
					ft_strdel(&object);
			}
			else
				mlx_pixel_put_to_image(rt->default_color, rt, x, y);
			x++;
		}
		y++;
	}
}
