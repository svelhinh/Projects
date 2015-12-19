/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 16:51:39 by svelhinh          #+#    #+#             */
/*   Updated: 2015/12/19 18:23:15 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int			main(int ac, char **av)
{
	int		error;
	int		fd;
	t_coord	**coord;
	t_varf	v;

	(void)ac;
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
	ft_resize_tab(*coord);
	ft_putcolor("default");
	return (0);
}
