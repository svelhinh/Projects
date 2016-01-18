/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtata <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 16:08:30 by vtata             #+#    #+#             */
/*   Updated: 2016/01/06 18:33:08 by vtata            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int			main(int ac, char **av)
{
	char	*str;
	int		fd;
	int		i;
	int		rt;

	i = 0;
	if (ac == 1)
	{
		fd = 0;
	}
	else
		fd = open(av[1], O_RDONLY);
	str = NULL;
	if (fd == -1)
		ft_putstr("OPEN ERROR\n");
	while ((rt = get_next_line(fd, &str)) > 0)
	{
		//ft_putstr("----MAIN---\n");
		//ft_putnbr(rt);
		//ft_putchar('\n');
		//ft_putstr("main:");
		ft_putstr(str);
		ft_putchar('\n');
		++i;
	}
	free(str);
	return (0);
}
