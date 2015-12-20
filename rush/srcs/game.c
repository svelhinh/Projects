/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 11:46:28 by svelhinh          #+#    #+#             */
/*   Updated: 2015/12/20 19:07:00 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
#define BUFF_SIZE 10

char	**ft_read_file(int fd)
{
	int ret;
	char buf[BUFF_SIZE + 1];
	char **m;
	char *tmp;

	tmp = ft_strnew(BUFF_SIZE);
	while ((ret = read(fd, buf, BUFF_SIZE)) && !ft_memchr(buf, '\n', 1))
	{
		buf[ret]= '\0';
		tmp = ft_strjoin(tmp, buf);
	}
	m = ft_strsplit(tmp, '\n');
	return (m);
}

void	ft_display_matches(char **m)
{
	int	i;
	int	matches;
	int nbspaces;

	i = 0;
	while (m[i])
	{
		matches = 0;
		nbspaces = 0;
		while (nbspaces < i)
		{
			ft_putchar(' ');
			nbspaces++;
		}
		while (matches < ft_atoi(m[i]))
		{
			ft_putchar('|');
			matches++;
		}
		ft_putchar('\n');
		i++;
	}
}

char	**ft_remove(char **m, int nbmr)
{
	int i;

	i = 0;
	while (m[i] && ft_strcmp(m[i], "0"))
		i++;
	i--;
	while (nbmr)
	{
		if (ft_atoi(m[i]) <= 0)
			i--;
		m[i] = ft_itoa(ft_atoi(m[i]) - 1);
		nbmr--;
	}
	return (m);
}

char	**ft_ia(char **m, int nbm)
{
	int nbmr;

	nbmr = 0;
	if ((nbm % 2 == 0 && nbm % 4 != 0) || nbm == 1)
		nbmr = 1;
	else if (nbm % 2 != 0)
		nbmr = 2;
	else if (nbm % 4 == 0)
		nbmr = 3;
	if (nbm != 0)
		m = ft_remove(m, nbmr);
	return (m);
}

int		ft_nbmatches(char **m)
{
	int i;
	int nbm;

	i = 0;
	nbm = 0;
	while (m[i])
	{
		nbm += ft_atoi(m[i]);
		i++;
	}
	return (nbm);
}

int		main(int ac, char **av)
{
	char buf[BUFF_SIZE + 1];
	int ret;
	int winner;
	int fd;
	char **m;
	int nbm;
	int turn;
	int i;
	int nbmr;

	winner = 2;
	m = NULL;
	fd = 0;
	nbm = 0;
	turn = 1;
	nbmr = 0;
	if (ac == 2)
		if ((fd = open(av[1], O_RDONLY)) == -1)
		{
			ft_putstr("ERROR\n");
			exit(0);
		}
	m = ft_read_file(fd);
	while (winner == 2)
	{
		ft_putcolor("cyan");
		ft_display_matches(m);
		nbm = ft_nbmatches(m);
		if (turn)
		{
			i = 0;
			while (ft_atoi(buf) < 1 || ft_atoi(buf) > 3
					|| ft_atoi(buf) > nbm || i == 0)
			{
				ft_putcolor("light blue");
				ft_putstr("\nHow many matches you want to remove ?\n");
				ft_putcolor("light yellow");
				ret = read(0, buf, BUFF_SIZE);
				buf[ret] = '\0';
				ft_putchar('\n');
				if (ft_atoi(buf) < 1 || ft_atoi(buf) > 3 || ft_atoi(buf) > nbm)
				{
					ft_putcolor("light red");
					ft_putstr("\nBAD ANSWER !!!");
				}
				i++;
			}
			nbmr = ft_atoi(buf);
			ft_remove(m, nbmr);
			turn = 0;
		}
		else
		{
			m = ft_ia(m, nbm);
			turn = 1;
			ft_putchar('\n');
		}
		nbm = ft_nbmatches(m);
		if (nbm == 0)
			winner = turn;
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
