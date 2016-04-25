/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 10:54:36 by svelhinh          #+#    #+#             */
/*   Updated: 2016/04/25 15:36:33 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		init_all(char *file, t_env *rt)
{
	rt->bg_color = 0;
	rt->w = 1280;
	rt->h = 720;
	rt->nbobj = 0;
	rt->keyup = 0;
	rt->keydown = 0;
	rt->keyleft = 0;
	rt->keyright = 0;
	count_objects(rt, file);
	init_camera(rt);
	// init_light(rt);
}
