/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 16:51:39 by svelhinh          #+#    #+#             */
/*   Updated: 2015/12/28 15:52:11 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_nbr_blk(t_coord *coord)
{
	int i;
	int tablen;

	i = 0;
	tablen = 2;
	while (coord)
	{
		coord = coord->next;
		i++;
	}
	while (tablen * tablen < i * 4)
		tablen++;
	return (tablen);
}

static void		ft_display(char **tab)
{
	int y;

	y = 0;
	while (tab[y])
	{
		ft_putstr(tab[y]);
		ft_putchar('\n');
		y++;
	}
}

static void		ft_exit(void)
{
	ft_putstr("error\n");
	exit(0);
}

static void		ft_notetri(t_coord **coord)
{
	t_coord	*tmp;
	int		i;

	tmp = *coord;
	i = 0;
	while (tmp)
	{
		if (i > 26)
			ft_exit();
		if (tmp->y[2] > tmp->y[1] + 1 || (tmp->x[0] != tmp->x[2]
					&& tmp->x[0] != tmp->x[3] && tmp->x[1] != tmp->x[2]
					&& tmp->x[1] != tmp->x[3] && tmp->y[0] != tmp->y[2]
					&& tmp->y[0] != tmp->y[3] && tmp->y[1] != tmp->y[2]
					&& tmp->y[1] != tmp->y[3]) || (tmp->x[0] == tmp->x[2]
					&& tmp->x[1] == tmp->x[3] && tmp->x[1] > tmp->x[0] + 1
					&& tmp->x[3] > tmp->x[2] + 1))
		{
			free(coord);
			free(tmp);
			ft_exit();
		}
		tmp = tmp->next;
		i++;
	}
	free(tmp);
}

int				main(int ac, char **av)
{
	t_coord	**coord;
	t_varf	v;

	(ac != 2) ? (ft_exit()) : (42);
	v.tab = NULL;
	v.file = ft_strnew(1);
	v.fd = open(av[1], O_RDONLY);
	v.y = 0;
	(v.fd == -1 || (v.error = ft_errors(v.fd, &v.file) == -1)
			|| close(v.fd) == -1) ? (ft_exit()) : ("yo");
	v.file = ft_letters(v.file);
	coord = ft_store(v.file);
	free(v.file);
	ft_notetri(coord);
	v.tab = ft_result(*coord, ft_nbr_blk(*coord));
	free(coord);
	ft_display(v.tab);
	free(v.tab);
	return (0);
}
