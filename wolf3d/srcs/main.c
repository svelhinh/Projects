/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 13:19:40 by svelhinh          #+#    #+#             */
/*   Updated: 2016/02/01 18:48:46 by svelhinh         ###   ########.fr       */
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
		nb_alea = rand() % 1;
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
	t_ray	r;

	r.i = 0;
	r.lvl = check_param(ac, av);
	if (ft_strcmp(r.lvl, "levels/lvl0"))
		ft_exit("Bad file name, please name your files lvl[number] ");
	(!(r.mlx = mlx_init())) ? (ft_exit("mlx_init() failed in main()")) : (0);
	if (!(r.win = mlx_new_window(r.mlx, SWIDTH, SHEIGHT, r.lvl)))
		ft_exit("mlx_new_window failed in main()");
	r.map = parser(r.lvl);
	load_tex(&r);
	mlx_expose_hook(r.win, expose, &r);
	mlx_hook(r.win, 2, 64, key, &r);
	//mlx_key_hook(r.win, key, &r);
	mlx_loop(r.mlx);
	return (0);
}
