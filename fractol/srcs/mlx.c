/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 10:40:08 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/18 18:11:52 by svelhinh         ###   ########.fr       */
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

int		zoom(int button, int x, int y, t_fract *e)
{
	(void)x;
	(void)y;
	if (button == 4)
	{
		e->x1 += 1;
		e->y2 -= 1;
		//printf("x1 = %f\nx2 = %f\ny1 = %f\ny2 = %f\n\n", e->x1, e->x2, e->y1, e->y2);
		e->fractx *= 1.2;
		e->fracty *= 1.2;
		draw(e);
	}
	if (button == 5)
	{
		e->x1 -= 1;
		e->y2 += 1;
		e->fractx /= 1.2;
		e->fracty /= 1.2;
		draw(e);
	}
	return (0);
}
