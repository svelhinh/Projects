/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 13:35:51 by svelhinh          #+#    #+#             */
/*   Updated: 2016/02/05 13:41:29 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

char	*check_param(int ac, char **av)
{
	char	*lvl;
	char	*tmp;
	char	*tmp2;
	int		nb_alea;

	if (ac == 1)
	{
		srand(time(NULL));
		nb_alea = rand() % 3;
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

int		check_lvl(char *lvl)
{
	int nb;

	if (!ft_strcmp(lvl, "levels/lvl0"))
		nb = 0;
	else if (!ft_strcmp(lvl, "levels/lvl1"))
		nb = 1;
	else if (!ft_strcmp(lvl, "levels/lvl2"))
		nb = 2;
	else
		nb = -1;
	return (nb);
}
