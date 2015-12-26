/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguirrie <sguirrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/05 18:45:56 by sguirrie          #+#    #+#             */
/*   Updated: 2015/12/09 13:08:45 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int     main(int ac, char **av)
{
    int     fd;
    char    *line;
	int		i;
	(void)ac;
	(void)av;

    //fd = open(av[1], O_RDONLY);
	fd = 0;
    if (fd == -1)
    {
        ft_putstr("open() error");
        return (1);
    }
	while ((i = get_next_line((int const)fd, &line)) > 0)
	{
		ft_putendl("LINE");
		ft_putendl(line);
        free (line);
	}
    return (1);
}
