/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 13:01:23 by svelhinh          #+#    #+#             */
/*   Updated: 2016/02/01 16:37:13 by svelhinh         ###   ########.fr       */
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
	int bpp;
	int sizeline;
	int endian;
	char *data;
	int w;
	int h;

	w = 64;
	h = 64;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 1000, "test");
	img = mlx_xpm_file_to_image(mlx, "../textures/bricks.xpm", &w, &h);
	data = mlx_get_data_addr(img, &bpp, &sizeline, &endian);

	int x = 0;
	while (x < 64 * 64)
	{
		printf("%d\n", data[x]);
		x++;
	}
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
