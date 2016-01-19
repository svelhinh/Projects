/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 10:40:08 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/19 18:16:38 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		mlx_pixel_put_to_image(t_fract *e)
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;

	b = (e->color & 0xFF0000) >> 16;
	g = (e->color & 0xFF00) >> 8;
	r = (e->color & 0xFF);
	e->data[e->y * e->size_line + e->x * e->bpp / 8] = r;
	e->data[e->y * e->size_line + e->x * e->bpp / 8 + 1] = g;
	e->data[e->y * e->size_line + e->x * e->bpp / 8 + 2] = b;
}

int			draw(t_fract *e)
{
	e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->data = mlx_get_data_addr(e->img, &e->bpp, &e->size_line, &e->endian);
	if (!ft_strcmp(e->fract, "mandelbrot"))
		mandelbrot(*e);
	else if (!ft_strcmp(e->fract, "julia"))
		julia(*e);
	/*else
	  other();*/
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_destroy_image(e->mlx, e->img);
	return (0);
}

int			key(int keycode)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

int			mouse(int x, int y, t_fract *e)
{
	static int sx = WIDTH / 2;
	static int sy = HEIGHT / 2;

	//printf("x = %d\nsx = %d\n\n", x, sx);
	if ((x != sx || y != sy) && x > 0 && y > 0 && x < WIDTH && y < HEIGHT &&
			!ft_strcmp(e->fract, "julia"))
	{
		if (x < sx)
			e->coeffx -= (0.01 * (sx - x));
		else if (x > sx)
			e->coeffx += (0.01 * (x - sx));
		if (y < sy)
			e->coeffy -= (0.02 * (sy - y));
		else if (y > sy)
			e->coeffy += (0.02 * (y - sy));
		if (x != sx)
			sx = x;
		if (y != sy)
			sy = y;
		draw(e);
	}
	return (0);
}

/*
 ** x1 -> limite gauche de l'image
 ** x2 -> limite droite de l'image
 ** y1 -> limite haute de l'image
 ** y2 -> limite basse de l'image
 ** --------------------------------
 ** Si on diminue x1 l'image bouge vers la droite. Si on diminue y1 l'image bouge
 ** vers le bas.
 */

int		zoom(int button, int x, int y, t_fract *e)
{
	float x_reel;
	float y_reel;

	x_reel = x / e->zoom + e->x1;
	y_reel = y / e->zoom + e->y1;
	printf("x = %d\ny = %d\n\n", x, y);
	if (button == 4)
	{
		e->zoom *= 1.2;
		e->x1 = x_reel - WIDTH / e->zoom / 2;
		e->y1 = y_reel - HEIGHT / e->zoom / 2;
		printf("x1 = %f\ny2 = %f\n\n", e->x1, e->y1);
		draw(e);
	}
	if (button == 5)
	{
		e->zoom /= 1.2;
		e->x1 = x_reel - WIDTH / e->zoom / 2;
		e->y1 = y_reel - HEIGHT / e->zoom / 2;
		printf("x1 = %f\ny2 = %f\n\n", e->x1, e->y1);
		draw(e);
	}
	return (0);
}
