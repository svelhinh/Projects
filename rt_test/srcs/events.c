/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 14:30:36 by svelhinh          #+#    #+#             */
/*   Updated: 2016/04/22 16:47:06 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		expose(t_rt *rt)
{
	if (rt->keyup == 1)
		rt->campos.z += SPEED;
	if (rt->keydown == 1)
		rt->campos.z -= SPEED;
	if (rt->keyleft == 1)
		rt->campos.x -= SPEED;
	if (rt->keyright == 1)
		rt->campos.x += SPEED;
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
	if (keycode == LEFT)
		rt->keyleft = 1;
	if (keycode == UP)
		rt->keyup = 1;
	if (keycode == RIGHT)
		rt->keyright = 1;
	if (keycode == DOWN)
		rt->keydown = 1;
	if (keycode == ESC)
	{
		mlx_destroy_window(rt->mlx, rt->win);
		exit(0);
	}
	return (0);
}

int		key_release(int keycode, t_rt *rt)
{
	if (keycode == LEFT)
		rt->keyleft = 0;
	if (keycode == UP)
		rt->keyup = 0;
	if (keycode == RIGHT)
		rt->keyright = 0;
	if (keycode == DOWN)
		rt->keydown = 0;
	return (0);
}
