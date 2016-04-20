/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 10:17:35 by svelhinh          #+#    #+#             */
/*   Updated: 2016/04/20 10:17:36 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		main(int ac, char **av)
{
	t_rt rt;

	if (ac != 2)
		(ac > 2) ? (ft_exit("\033[31mToo many parameters\n")) :
			(ft_exit("\033[31mNot enough parameters\n"));
	if (av[1][ft_strlen(av[1]) - 3] == '.' && av[1][ft_strlen(av[1]) - 2] == 'r'
			&& av[1][ft_strlen(av[1]) - 1] == 't')
		global_parser(av[1], &rt);
	else
		ft_exit("\033[31mFiles must have .rt extension\n");
	(!(rt.mlx = mlx_init())) ? (ft_exit("mlx_init() failed in main()")) : (0);
	if (!(rt.win = mlx_new_window(rt.mlx, rt.w, rt.h, "RTV1")))
		ft_exit("mlx_new_window() in main() failed");
	mlx_hook(rt.win, 2, (1L << 0), key_press, &rt);
	mlx_loop_hook(rt.mlx, expose, &rt);
	mlx_loop(rt.mlx);
	return (0);
}