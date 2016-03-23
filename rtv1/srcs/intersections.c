/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 10:41:50 by svelhinh          #+#    #+#             */
/*   Updated: 2016/03/22 11:39:43 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static char	*intersect_sphere(char *object)
{
	if (ft_strcmp(object, "sphere"))
	{
		(object) ? (ft_strdel(&object)) : (0);
		object = ft_strdup("sphere");
	}
	return (object);
}

static char	*intersect_plane(char *object)
{
	if (ft_strcmp(object, "plane"))
	{
		(object) ? (ft_strdel(&object)) : (0);
		object = ft_strdup("plane");
	}
	return (object);
}

static char	*intersect_cylinder(char *object)
{
	if (ft_strcmp(object, "cylinder"))
	{
		(object) ? (ft_strdel(&object)) : (0);
		object = ft_strdup("cylinder");
	}
	return (object);
}

static char	*intersect_cone(char *object)
{
	if (ft_strcmp(object, "cone"))
	{
		(object) ? (ft_strdel(&object)) : (0);
		object = ft_strdup("cone");
	}
	return (object);
}

char		*intersect(t_rt *rt, int *currentobj, char *object)
{
	int			i;
	float		t;
	int			imax;
	float		tmp;

	i = 0;
	t = 200000;
	imax = (rt->nbp > rt->nbs) ? (rt->nbp) : (rt->nbs);
	imax = (rt->nbc > imax) ? (rt->nbc) : (imax);
	imax = (rt->nbco > imax) ? (rt->nbco) : (imax);
	while (i < imax)
	{
		if (i < rt->nbs && sphere(&rt->r, &rt->s[i], &t))
		{
			*currentobj = i;
			object = intersect_sphere(object);
		}
		if (i < rt->nbp && plane(&rt->r, &rt->p[i], &t))
		{
			*currentobj = i;
			object = intersect_plane(object);
		}
		if (i < rt->nbc && cylinder(&rt->r, &rt->c[i], &t))
		{
			*currentobj = i;
			object = intersect_cylinder(object);
		}
		if (i < rt->nbco && cone(&rt->r, &rt->co[i], &t))
		{
			*currentobj = i;
			object = intersect_cone(object);
		}
		i++;
	}
	if (*currentobj != -1)
	{
<<<<<<< HEAD
		tmp = 0;
		if (!ft_strcmp(object, "plane"))
			light_plane(rt, t, tmp, *currentobj);
		else if (!ft_strcmp(object, "cylinder"))
			light_cylinder(rt, t, tmp, *currentobj);
		else if (!ft_strcmp(object, "cone"))
			light_cone(rt, t, tmp, *currentobj);
		else if (!ft_strcmp(object, "sphere"))
			light_sphere(rt, t, tmp, *currentobj);
=======
		//ft_putnbrendl(*currentobj);
		scaled = vectorscale(t, &rt->r.dir);
		newstart = vectoradd(&rt->r.start, &scaled);
		normal = vectorsub(&newstart, &rt->s[*currentobj].pos, 0);
		tmp = vectordot(&normal, &normal, 0);
		if (tmp != 0)
		{
			tmp = 1 / sqrt(tmp);
			normal = vectorscale(tmp, &normal);
			i = 0;
			while (i < 1)
			{
				currentlight = rt->lights[i];
				dist = vectorsub(&currentlight.pos, &newstart, 0);
				if (vectordot(&normal, &dist, 0) > 0)
				{
					tmp = sqrt(vectordot(&dist, &dist, 0));
					if (t > 0)
					{
						light_ray.start = newstart;
						light_ray.dir = vectorscale((1 / t), &dist);
						tmp = vectordot(&light_ray.dir, &normal, 0) * rt->coef;
						rt->pixel_color += tmp * currentlight.color + rt->s[*currentobj].color;
					}
				}
				i++;
			}
		}
>>>>>>> 9da8e16bc074a19e2f992c9425955b5289259946
	}
	return (object);
}
