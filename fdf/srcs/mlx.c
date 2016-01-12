/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/03 10:51:41 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/12 17:35:40 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		expose_hook(t_fdf *v)
{
	v->img = mlx_new_image(v->mlx, v->width, v->height);
	v->data = mlx_get_data_addr(v->img, &v->bpp, &v->size_line, &v->endian);
	put_lines1(*v);
	put_lines2(*v);
	mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
	mlx_destroy_image(v->mlx, v->img);
	return (0);
}

void	deplacement(int keycode, t_fdf *v)
{
	if (keycode == 124)
	{
		v->x2 -= 50;
		expose_hook(v);
	}
	if (keycode == 123)
	{
		v->x2 += 50;
		expose_hook(v);
	}
	if (keycode == 126)
	{
		v->y2 += 50;
		expose_hook(v);
	}
	if (keycode == 125)
	{
		v->y2 -= 50;
		expose_hook(v);
	}
}

int		key_hook(int keycode, t_fdf *v)
{
	if (keycode == 53)
		exit(0);
	deplacement(keycode, v);
	if (keycode == 36)
	{
		v->zoom /= 2;
		expose_hook(v);
	}
	if (keycode == 32)
	{
		v->alti += (0.2 * v->zoom);
		expose_hook(v);
	}
	if (keycode == 38)
	{
		v->alti -= (0.2 * v->zoom);
		expose_hook(v);
	}
	return (0);
}

int		mouse_hook(int button, int x, int y, t_fdf *v)
{
	if (button == 1)
	{
		v->x2 = x;
		v->y2 = y;
		expose_hook(v);
	}
	if (button == 4)
	{
		v->zoom += 0.01;
		expose_hook(v);
	}
	if (button == 5 && v->zoom > 0.01)
	{
		v->zoom -= 0.01;
		expose_hook(v);
	}
	return (0);
}
