/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 11:38:00 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/24 11:58:08 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "gnl/get_next_line.h"
#include "libft/includes/libft.h"

int		main(int ac, char **av)
{
	int fd = open(av[1], O_RDONLY);
	char *line;
	(void)ac;

	get_next_line(fd, &line);
	//ft_putstr(line);
	//ft_putchar('\n');
	//sleep(15);
	return (0);
}
