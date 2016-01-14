/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 17:15:05 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/14 17:33:30 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	display_params(void)
{
	ft_putstr("mandelbrot\n");
	ft_putstr("julia\n");
	ft_putstr("other\n");
}

char	*

int		main(int ac, char **av)
{
	if (ac == 2 && check_fract(av[1]))
	{
		
	}
	else
		display_params();
	return (0);
}
