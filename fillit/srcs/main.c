/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 16:51:39 by svelhinh          #+#    #+#             */
/*   Updated: 2015/12/23 13:46:55 by stoussay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			main(int ac, char **av)
{
	int		error;
	int		fd;
	t_coord	**coord;
	t_varf	v;
	char **tab;
	int y;

	(void)ac;
	tab = NULL;
	v.file = ft_strnew(1);
	ft_putcolor("light green");
	fd = open(av[1], O_RDONLY);
	y = 0;
	if (fd == -1 || (error = ft_errors(fd, &v.file) == -1))
	{
		ft_putstr("error\n\n");
		ft_putcolor("default");
		return (0);
	}
	if (close(fd) == -1)
	{
		ft_putstr("error");
		ft_putcolor("default");
		return (0);
	}
	v.file = ft_letters(v.file);
	coord = ft_store(v.file);
	tab = solve((*coord), 2);
	while (tab[y])
	{
		ft_putstr(tab[y]);
		ft_putchar('\n');
		y++;
	}
	ft_putchar('\n');
	ft_putcolor("default");
	return (0);
}
