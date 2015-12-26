/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 14:57:58 by svelhinh          #+#    #+#             */
/*   Updated: 2015/12/26 18:01:22 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <unistd.h>

int		main(void)
{
	void	*mlx;
	void	*win;
	int x;
	int y;
	int r;
	int g;

	y = 100;
	r = 255;
	g = 127;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 1000, "42");
	sleep(2);
	while (y < 500)
	{
		x = 100;
		while (x < 500)
		{
			mlx_pixel_put(mlx, win, x, y, 0xAAFF00);
			x++;
		}
		y++;
	}
	mlx_loop(mlx);
	return (0);
}
