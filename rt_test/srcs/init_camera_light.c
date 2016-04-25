/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera_light.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 15:28:32 by svelhinh          #+#    #+#             */
/*   Updated: 2016/04/20 15:36:31 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	init_light(t_rt *rt)
{
	rt->light.pos.x = 0;
	rt->light.pos.y = 0;
	rt->light.pos.z = 0;
	rt->light.intensity.r = 0;
	rt->light.intensity.g = 0;
	rt->light.intensity.b = 0;
}

void	init_camera(t_rt *rt)
{
	rt->campos.x = 0;
	rt->campos.y = 0;
	rt->campos.z = 0;
	rt->r.dir.x = 0;
	rt->r.dir.y = 0;
	rt->r.dir.z = -rt->w;
}
