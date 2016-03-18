/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 10:54:36 by svelhinh          #+#    #+#             */
/*   Updated: 2016/03/18 11:09:20 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		init_all(char *file, t_rt *rt)
{
	rt->default_color = 0;
	init_camera(rt);
	init_light(rt);
	init_sphere(file, rt);
	init_plane(file, rt);
	init_cylinder(file, rt);
	init_cone(file, rt);
}
