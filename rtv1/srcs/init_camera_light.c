/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera_lights.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 10:16:17 by svelhinh          #+#    #+#             */
/*   Updated: 2016/03/24 18:26:09 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	init_light(t_rt *rt)
{
	rt->light.pos.x = 0;
	rt->light.pos.y = 0;
	rt->light.pos.z = 0;
	rt->light.intensity.red = 0;
	rt->light.intensity.green = 0;
	rt->light.intensity.blue = 0;
}

void	init_camera(t_rt *rt)
{
	rt->campos.x = 0;
	rt->campos.y = 0;
	rt->campos.z = 0;
}
