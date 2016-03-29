/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 10:41:50 by svelhinh          #+#    #+#             */
/*   Updated: 2016/03/29 18:07:35 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static char	*intersect_sphere_plane(char *object, t_rt *rt, int i, int *cobj)
{
	if (i < rt->nbs && sphere(&rt->r, &rt->s[i], &rt->t))
	{
		*cobj = i;
		if (ft_strcmp(object, "sphere"))
		{
			(object) ? (ft_strdel(&object)) : (0);
			object = ft_strdup("sphere");
		}
	}
	if (i < rt->nbp && plane(&rt->r, &rt->p[i], &rt->t))
	{
		*cobj = i;
		if (ft_strcmp(object, "plane"))
		{
			(object) ? (ft_strdel(&object)) : (0);
			object = ft_strdup("plane");
		}
	}
	return (object);
}

static char	*intersect_cylinder_cone(char *object, t_rt *rt, int i, int *cobj)
{
	if (i < rt->nbc && cylinder(&rt->r, &rt->c[i], &rt->t))
	{
		*cobj = i;
		if (ft_strcmp(object, "cylinder"))
		{
			(object) ? (ft_strdel(&object)) : (0);
			object = ft_strdup("cylinder");
		}
	}
	if (i < rt->nbco && cone(&rt->r, &rt->co[i], &rt->t))
	{
		*cobj = i;
		if (ft_strcmp(object, "cone"))
		{
			(object) ? (ft_strdel(&object)) : (0);
			object = ft_strdup("cone");
		}
	}
	return (object);
}

static void	light(t_rt *rt, int *currentobj, char *object)
{
	float	tmp;

	if (*currentobj != -1)
	{
		tmp = 0;
		if (!ft_strcmp(object, "plane"))
			light_plane(rt, rt->t, *currentobj);
		else if (!ft_strcmp(object, "cylinder"))
			light_cylinder(rt, rt->t, *currentobj);
		else if (!ft_strcmp(object, "cone"))
			light_cone(rt, rt->t, tmp, *currentobj);
		else if (!ft_strcmp(object, "sphere"))
			light_sphere(rt, rt->t, tmp, *currentobj);
	}
}

char		*intersect(t_rt *rt, int *currentobj, char *object)
{
	int			i;
	int			imax;

	i = 0;
	rt->t = 200000;
	imax = (rt->nbp > rt->nbs) ? (rt->nbp) : (rt->nbs);
	imax = (rt->nbc > imax) ? (rt->nbc) : (imax);
	imax = (rt->nbco > imax) ? (rt->nbco) : (imax);
	while (i < imax)
	{
		object = intersect_sphere_plane(object, rt, i, currentobj);
		object = intersect_cylinder_cone(object, rt, i, currentobj);
		i++;
	}
	light(rt, currentobj, object);
	return (object);
}

int			shadows(t_rt *rt, t_ray *light, float t)
{
	int		i;
	int		imax;

	i = 0;
	imax = (rt->nbs > rt->nbc) ? (rt->nbs) : (rt->nbc);
	imax = (rt->nbco > imax) ? (rt->nbco) : (imax);
	while (i < imax)
	{
		if ((i < rt->nbs && sphere(light, &rt->s[i], &t))
				|| (i < rt->nbc && cylinder(light, &rt->c[i], &t))
				|| (i < rt->nbco && cone(light, &rt->co[i], &t)))
			return (1);
		i++;
	}
	return (0);
}
