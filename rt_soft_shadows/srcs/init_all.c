/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 10:54:36 by svelhinh          #+#    #+#             */
/*   Updated: 2016/05/26 15:22:07 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	random_val(t_env *rt)
{
	int i;

	srand(time(NULL));
	if (!(rt->random = (t_vector *)malloc(sizeof(t_vector) * 64)))
		ft_exit("malloc of rt->random failed in random_val()");
	i = 0;
	while (i < 64)
	{
		rt->random[i].x = -16 + ((float)rand() / RAND_MAX * 32);
		rt->random[i].y = -16 + ((float)rand() / RAND_MAX * 32);
		rt->random[i].z = -16 + ((float)rand() / RAND_MAX * 32);
		i++;
	}
}

void		init_all(char *file, t_env *rt)
{
	rt->bg_color.r = 0;
	rt->bg_color.g = 0;
	rt->bg_color.b = 0;
	rt->w = 1280;
	rt->h = 720;
	rt->xx = 0;
	rt->zz = 0;
	rt->nbobj = 0;
	rt->nblight = 0;
	rt->keyup = 0;
	rt->keydown = 0;
	rt->keyleft = 0;
	rt->keyright = 0;
	rt->max_reflect = 0;
	rt->max_refract = 0;
	rt->menu = 0;
	rt->rotcam = 0;
	rt->effect = 0;
	rt->ambient = 0.3;
	random_val(rt);
	count_objects(rt, file);
	init_camera(rt);
	count_light(rt, file);
}
