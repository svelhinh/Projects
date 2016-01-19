/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 17:15:05 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/19 17:04:40 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	display_params(void)
{
	ft_putstr("mandelbrot\n");
	ft_putstr("julia\n");
	ft_putstr("other\n");
}

static char	*check_fract(char *s)
{
	if (!ft_strcmp(s, "mandelbrot"))
		return ("mandelbrot");
	if (!ft_strcmp(s, "julia"))
		return ("julia");
	if (!ft_strcmp(s, "other"))
		return ("other");
	return (NULL);
}

int			main(int ac, char **av)
{
	t_fract	e;

	if (ac == 2 && (e.fract = check_fract(av[1])))
	{
		var_init(&e);
		e.mlx = mlx_init();
		e.win = mlx_new_window(e.mlx, WIDTH, HEIGHT, "fractol");
		mlx_expose_hook(e.win, draw, &e);
		mlx_key_hook(e.win, key, &e);
		mlx_mouse_hook(e.win, zoom, &e);
		mlx_hook(e.win, 6, (1L << 6), mouse, &e);
		mlx_loop(e.mlx);
	}
	else
		display_params();
	return (0);
}
