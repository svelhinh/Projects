/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 13:01:23 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/28 15:06:56 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int		main(void)
{
	void *win;
	void *mlx;
	void *img;
	int w;
	int h;

	w = 255;
	h = 255;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 1000, "test");
	img = mlx_xpm_file_to_image(mlx, "../textures/mur.xpm", &w, &h);
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
