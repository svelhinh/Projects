/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 11:21:40 by svelhinh          #+#    #+#             */
/*   Updated: 2016/03/11 10:36:17 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int		sphere(t_ray *r, t_sphere *s, float *t)
{
	t_vector3d	dist;
	float		tab[2];		/* tab[0] = t0, tab[1] = t1 */
	float		b;
	float		d;
	int			retval;

	dist = vectorsub(&s->pos, &r->start);
	b = vectordot(&r->dir, &dist);
	d = pow(b, 2) - vectordot(&dist, &dist) + pow(s->radius, 2);
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

static char		*intersect(t_rt *rt, int *currentobj, char *object)
{
	int		i;
	float	t;

	i = 0;
	t = 20000;
	while (i < rt->nbs)			// Ne pas oublier de trouver le i max
	{
		if (i < rt->nbs && sphere(&rt->r, &rt->s[i], &t))
		{
			*currentobj = i;
			if (!ft_strstr(object, "sphere"))
			{
				if (object)
					ft_strdel(&object);
				object = ft_strdup("sphere");
			}
		}
		if (i < rt->nbp && plane(&rt->r, &rt->p[i], &t))
		{
			*currentobj = i;
			if (!ft_strstr(object, "plane"))
			{
				if (object)
					ft_strdel(&object);
				object = ft_strdup("plane");
			}
		}
		i++;
	}
	return (object);
}

void			render(t_rt *rt)
{
	char		*object;
	/*float		t;
	int			i;*/
	int			currentobj;
	int			x;
	int			y;

	y = 0;
	while (y < SH)
	{
		x = 0;
		while (x < SW)
		{
			rt->r.start.x = (float)x + rt->campos.x;
			rt->r.start.y = (float)y + rt->campos.y;
			rt->r.start.z = -10000 + rt->campos.z;
			currentobj = -1;
			object = NULL;
			object = intersect(rt, &currentobj, object);
			/*while (i < rt->nbs)			// Ne pas oublier de trouver le i max
			  {
			  if (i < rt->nbs && sphere(&rt->r, &rt->s[i], &t))
			  {
			  currentobj = i;
			  if (!ft_strstr(object, "sphere"))
			  {
			  if (object)
			  ft_strdel(&object);
			  object = ft_strdup("sphere");
			  }
			  }
			  if (i < rt->nbp && plane(&rt->r, &rt->p[i], &t))
			  {
			  currentobj = i;
			  if (!ft_strstr(object, "plane"))
			  {
			  if (object)
			  ft_strdel(&object);
			  object = ft_strdup("plane");
			  }
			  }
			  i++;
			  }*/
			if (currentobj != -1)
			{
				if (ft_strstr("sphere", object))
					mlx_pixel_put_to_image(rt->s[currentobj].color, rt, x, y);
				else if (ft_strstr("plane", object))
					mlx_pixel_put_to_image(rt->p[currentobj].color, rt, x, y);
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
