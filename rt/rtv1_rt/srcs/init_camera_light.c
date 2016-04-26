/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera_light.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 15:28:32 by svelhinh          #+#    #+#             */
/*   Updated: 2016/04/25 15:38:36 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	init_light(t_env *rt)
{
	rt->light.x = 0;
	rt->light.y = 0;
	rt->light.z = 0;
}

void	init_camera(t_env *rt)
{
	rt->eye.x = 0;
	rt->eye.y = 0;
	rt->eye.z = 0;
}