/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 13:19:40 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/22 17:40:12 by svelhinh         ###   ########.fr       */
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
	int		nb_alea;

	if (ac == 1)
	{
		srand(time(NULL));
		nb_alea = rand() % 4;
		tmp = ft_strdup("lvl");
		lvl = ft_strjoin(tmp, ft_itoa(nb_alea));
		free(tmp);
		return (lvl);
	}
	else if (ac == 2)
		return (av[1]);
	else
	{
		ft_putcolor("light red");
		ft_exit("Trop de parametres");
	}
	return (NULL);
}

int		main(int ac, char **av)
{
	char *lvl;

	lvl = check_param(ac, av);
	ft_putendl(lvl);
	return 0;
}
