/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 14:30:36 by svelhinh          #+#    #+#             */
/*   Updated: 2016/04/20 14:30:37 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		expose(t_rt *rt)
{
	if (!(rt->img = mlx_new_image(rt->mlx, rt->w, rt->h)))
		ft_exit("mlx_new_image() in expose() failed");
	rt->data = mlx_get_data_addr(rt->img, &rt->bpp, &rt->size_line,
			&rt->endian);
	raytracer(rt);
	mlx_put_image_to_window(rt->mlx, rt->win, rt->img, 0, 0);
	mlx_destroy_image(rt->mlx, rt->img);
	return (0);
}

int		key_press(int keycode, t_rt *rt)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(rt->mlx, rt->win);
		exit(0);
	}
	return (0);
}