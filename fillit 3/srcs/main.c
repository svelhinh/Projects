/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 16:51:39 by svelhinh          #+#    #+#             */
/*   Updated: 2015/12/22 15:49:23 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int			main(int ac, char **av)
{
	int		error;
	int		fd;
	int		i;
	t_coord	**coord;
	t_varf	v;
	char **tab;

	(void)ac;
	tab = NULL;
	v.file = ft_strnew(1);
	ft_putcolor("light green");
	fd = open(av[1], O_RDONLY);
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
	ft_puttab(v.file, 4, 16);
	ft_putstr("// -------------------------------- \\\\\n\n");
	coord = ft_store(v.file);
	ft_resize_tab(*coord, 2, tab);
//	while (*coord)
//	{
//		printf("c = %c\n\n", (*coord)->c);
		i = 0;
//		while (i < 4)
//		{
//			printf("x = %d\n", (*coord)->x[i]);
//			printf("y = %d\n\n", (*coord)->y[i]);
//			i++;
//		}
//		(*coord) = (*coord)->next;
//	}
//	while (tab[i])
//	{
//		printf("tab = %s\n", tab[i]);
//		i++;
//	}
	ft_putcolor("default");
	return (0);
}
