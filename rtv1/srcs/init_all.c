/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 10:54:36 by svelhinh          #+#    #+#             */
/*   Updated: 2016/03/29 14:53:55 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		init_all(char *file, t_rt *rt)
{
	rt->default_color = 0;
	rt->nbs = 0;
	rt->nbp = 0;
	rt->nbc = 0;
	rt->nbco = 0;
	count_objects(rt, file);
	init_camera(rt);
	init_light(rt);
	init_sphere(rt);
	init_plane(rt);
	init_cylinder(rt);
	init_cone(rt);
}
