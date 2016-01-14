/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 14:05:10 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/14 12:40:31 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <complex.h>
#include <math.h>
#include <mlx.h>
#include <stdio.h>

int		main(void)
{
	void			*mlx;
	void			*win;

	// On definit la zone que l'on dessine. Ici, la fractale entiere
	float			x1 = -2.2;//-2.1;
	float			x2 = 0.8;//0.6;
	float			y1 = -1.2;//-1.2;
	float			y2 = 1.2;//1.2;
	float			img_x = 2000;
	float			img_y = 1300;

	// On calcule le zoom de l'image
	float			zoom_x = img_x / (x2 - x1);
	float			zoom_y = img_y / (y2 - y1);

	int				y;
	int				x;
	float complex	c;
	float complex	z;
	int				i;
	int				i_max = 50;
	int				color;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 2000, 1300, "fractol");
	y = 0;
	while (y < img_y)
	{
		x = 0;
		while (x < img_x)
		{
			z = (x / zoom_x + x1) + (y / zoom_y + y1) * _Complex_I;
			c = z;//-0.772691322542185 + 0.124281466072787 * _Complex_I;
			color = 0x000000;
			i = 0;
			while (creal(z) * creal(z) + cimag(z) * cimag(z) < 4 && i < i_max)
			{
				z = cpow(z, 2) + c;
				color += 0x404040;
				i++;
			}
			if (i == i_max)
				mlx_pixel_put(mlx, win, x, y, color);
			x++;
		}
		y++;
	}
	mlx_loop(mlx);
	return (0);
}
