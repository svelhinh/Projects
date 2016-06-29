/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 10:40:08 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/20 18:05:17 by svelhinh         ###   ########.fr       */
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
	else if (!ft_strcmp(e->fract, "illuminati"))
		illuminati(*e);
	else if (!ft_strcmp(e->fract, "water drop"))
		waterdrop(*e);
	else if (!ft_strcmp(e->fract, "salad"))
		salad(*e);
	else if (!ft_strcmp(e->fract, "eye"))
		eye(*e);
	else if (!ft_strcmp(e->fract, "star"))
		star(*e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_destroy_image(e->mlx, e->img);
	return (0);
}

int			key(int keycode, t_fract *e)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 126 || keycode == 125 || keycode == 123 || keycode == 124)
	{
		if (keycode == 126)
			e->y1 += 0.1;
		if (keycode == 125)
			e->y1 -= 0.1;
		if (keycode == 123)
			e->x1 += 0.1;
		if (keycode == 124)
			e->x1 -= 0.1;
		draw(e);
	}
	return (0);
}

int			mouse(int x, int y, t_fract *e)
{
	static int sx = WIDTH / 2;
	static int sy = HEIGHT / 2;

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

int			zoom(int button, int x, int y, t_fract *e)
{
	t_fract		n;

	if (button == 4 || button == 5)
	{
		n.factor = 1.2;
		n.x_reel = x / e->zoom + e->x1;
		n.y_reel = y / e->zoom + e->y1;
		if (button == 4)
		{
			e->zoom *= n.factor;
			e->i_max *= n.factor;
		}
		else
		{
			e->zoom /= n.factor;
			(e->i_max > 50) ? (e->i_max /= n.factor) : (e->i_max = 50);
		}
		e->x1 = n.x_reel - WIDTH / e->zoom / 2;
		e->y1 = n.y_reel - HEIGHT / e->zoom / 2;
		draw(e);
	}
	return (0);
}
