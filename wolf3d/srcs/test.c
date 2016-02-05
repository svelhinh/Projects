/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 13:01:23 by svelhinh          #+#    #+#             */
/*   Updated: 2016/02/05 14:22:37 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#define SWIDTH 1250
#define SHEIGHT 1000
#define MWIDTH SWIDTH / 4
#define MHEIGHT SHEIGHT / 4

int		main(void)
{
	void *win;
	void *mlx;
	int x;
	int y;
	int map[5][5] = {{1, 1, 1, 1, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 0, 1}, {1, 1, 1, 1, 1}};

	y = 0;
	mlx = mlx_init();
	win = mlx_new_window(mlx, SWIDTH, SHEIGHT, "test");
	while (y < 10)
	{
		x = 0;
		while (x < 10)
		{
			if (map[y][x] != 0)
				mlx_pixel_put(mlx, win, x, y, 0xffffff);
			x += 2;
		}
		y += 2;
	}
	mlx_loop(mlx);
	return (0);
}
