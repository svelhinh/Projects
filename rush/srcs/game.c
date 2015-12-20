/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 11:46:28 by svelhinh          #+#    #+#             */
/*   Updated: 2015/12/20 15:18:47 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>		// a enlever
#include "libft.h"
#define BUFF_SIZE 20000

char	**ft_read_file(int fd)
{
	int ret;
	char buf[BUFF_SIZE + 1];
	char **m;
	char *tmp;

	tmp = ft_strnew(BUFF_SIZE);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret]= '\0';
		tmp = ft_strjoin(tmp, buf);
	}
	m = ft_strsplit(tmp, '\n');
	return (m);
}

int		main(int ac, char **av)
{
	int	nbmatches;
	char buf[BUFF_SIZE + 1];
	int ret;
	int winner;
	int fd;
	char **m;

	nbmatches = 62;
	winner = 2;
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		m = ft_read_file(fd);
	}
	while (winner == 2)
	{
		ft_putcolor("cyan");
		ft_putnbr(nbmatches);		// A remplacer par le fichier des allumettes
		while (ft_atoi(buf) < 1 || ft_atoi(buf) > 3)
		{
			ft_putcolor("light blue");
			ft_putstr("\nHow many matches you want to remove ?\n");
			ft_putcolor("light yellow");
			ret = read(0, buf, BUFF_SIZE);
			buf[ret] = '\0';
			if (ft_atoi(buf) < 1 || ft_atoi(buf) > 3)
			{
				ft_putcolor("light red");
				ft_putstr("\nBAD ANSWER !!!");
			}
		}
		winner = 0;
	}
	if (winner == 0)
	{
		ft_putcolor("light red");
		ft_putstr("\n\nI win ;)\nMaybe next time\n");
	}
	if (winner == 1)
	{
		ft_putcolor("light green");
		ft_putstr("\n\nYou win :(\nGG\n");
	}
	return (0);
}
