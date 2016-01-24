/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 13:19:40 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/24 11:37:35 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_exit(char *s)
{
	perror(s);
	exit(0);
}

char	*check_param(int ac, char **av)
{
	char	*lvl;
	char	*tmp;
	char	*tmp2;
	int		nb_alea;

	if (ac == 1)
	{
		srand(time(NULL));
		nb_alea = rand() % 4;
		tmp = ft_strdup("levels/lvl");
		tmp2 = ft_itoa(nb_alea);
		lvl = ft_strjoin(tmp, tmp2);
		ft_strdel(&tmp);
		ft_strdel(&tmp2);
		return (lvl);
	}
	else if (ac == 2)
		return (ft_strjoin("levels/", av[1]));
	else
	{
		ft_putcolor("light red");
		ft_exit("Too many parameters");
	}
	return (NULL);
}

int		main(int ac, char **av)
{
	t_env	e;

	e.lvl = check_param(ac, av);
	(!(e.mlx = mlx_init())) ? (ft_exit("mlx_init() failed in main()")) : (0);
	if (!(e.win = mlx_new_window(e.mlx, SWIDTH, SHEIGHT, e.lvl)))
		ft_exit("mlx_new_window failed in main()");
	mlx_expose_hook(e.win, expose, &e);
	mlx_key_hook(e.win, exit_window, &e);
	mlx_loop(e.mlx);
	return (0);
}
