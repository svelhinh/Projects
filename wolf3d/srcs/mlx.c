/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/23 10:16:09 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/25 14:00:15 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		expose(t_env *e)
{
	t_coords c;

	e->img = mlx_new_image(e->mlx, SWIDTH, SHEIGHT);
	c.data = mlx_get_data_addr(e->img, &c.bpp, &c.size_line, &c.endian);
	raycasting(*e);
	//mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_destroy_image(e->mlx, e->img);
	return (0);
}

int		exit_window(int keycode)
{
	//ft_putnbrendl(keycode);
	if (keycode == 53)		//	Mac OS
	//if (keycode == 65307)	//	Linux
		exit(0);
	return (0);
}
