/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 09:40:41 by svelhinh          #+#    #+#             */
/*   Updated: 2015/12/11 11:14:00 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include "sys/types.h"
#include "sys/stat.h"
#include "sys/fcntl.h"
#include <stdio.h>

int         main(int ac, char **av)
{
	(void)ac;
	int         fd;
	char        *line;
	int         ret;
	int         i;

	fd = open(av[1], O_RDONLY);
	i = 0;
	while ((ret = get_next_line(fd, &line)) != 0)
	{
		if (ret == -1)
		{
			write(2, "error\n", 6);
			break ;
		}
		else if (ret > 0)
		{
			printf("line %d: %s\n", i, line);
			free(line);
			line = NULL;
		}
		i++;
	}
	free(line);
	line = NULL;
	close(fd);
	while(42);
	return (0);
}
