/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 15:30:23 by svelhinh          #+#    #+#             */
/*   Updated: 2016/03/18 10:35:37 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		expose(t_rt *rt)
{
	if (!(rt->img = mlx_new_image(rt->mlx, SW, SH)))
		ft_exit("mlx_new_image() in expose() failed");
	rt->data = mlx_get_data_addr(rt->img, &rt->bpp, &rt->size_line,
			&rt->endian);
	render(rt);
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

int		key_release(int keycode, t_rt *rt)
{
	(void)keycode;
	(void)rt;
	return (0);
}
