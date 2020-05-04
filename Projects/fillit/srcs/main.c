/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 16:51:39 by svelhinh          #+#    #+#             */
/*   Updated: 2015/12/31 12:34:42 by svelhinh         ###   ########.fr       */
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

void			ft_exit(void)
{
	ft_putstr("error\n");
	exit(0);
}

int				main(int ac, char **av)
{
	t_coord	**coord;
	t_varf	v;

	(ac != 2) ? (ft_exit()) : (0);
	v.tab = NULL;
	v.file = ft_strnew(1);
	((v.fd = open(av[1], O_RDONLY)) == -1) ? (ft_exit()) : (0);
	ft_check_tetri(v.fd);
	(close(v.fd) == -1) ? (ft_exit()) : (0);
	((v.fd = open(av[1], O_RDONLY)) == -1) ? (ft_exit()) : (0);
	ft_errors(v.fd, &v.file);
	(close(v.fd) == -1) ? (ft_exit()) : (0);
	v.file = ft_letters(v.file);
	coord = ft_store(v.file);
	free(v.file);
	v.tab = ft_result(*coord, ft_nbr_blk(*coord));
	free(coord);
	ft_display(v.tab);
	free(v.tab);
	return (0);
}
