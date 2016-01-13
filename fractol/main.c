/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 14:05:10 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/13 17:35:00 by svelhinh         ###   ########.fr       */
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
	float			x1 = -1.5;
	float			x2 = 1.5;
	float			y1 = -1.5;
	float			y2 = 1.5;
	float			zoom = 500;		// Pour une distance de 1 sur le plan, on a 100 pixels sur l'image

	// On calcule la taille de l'image
	float			ximg = (x2 - x1) * zoom;
	float			yimg = (y2 - y1) * zoom;

	int				x = 0;
	int				y;
	float complex	c;
	float complex	z;
	int				color;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 2000, 1300, "fractol");
	while (x < ximg)
	{
		y = 0;
		while (y < yimg)
		{
			c = /*(x / zoom + x1) + (y / zoom + y1) * _Complex_I*/-0.0986 + 0.65186 * _Complex_I;
			z = (x / zoom + x1) + (y / zoom + y1) * _Complex_I;
			color = 0x000000;
			while (creal(z) * creal(z) + cimag(z) * cimag(z) < 4)
			{
				z = z*z + c;
				color += 10;
			}
			mlx_pixel_put(mlx, win, x, y, color);
			y++;
		}
		x++;
	}
	mlx_loop(mlx);
	return (0);
}
