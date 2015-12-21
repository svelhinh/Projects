/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 11:46:28 by svelhinh          #+#    #+#             */
/*   Updated: 2015/12/21 11:39:22 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

int		main(int ac, char **av)
{
	t_alcu v;

	v.m = NULL;
	v.fd = 0;
	if (ac == 2)
		if ((v.fd = open(av[1], O_RDONLY)) == -1)
		{
			ft_putcolor("red");
			ft_putstr("ERROR\n");
			exit(0);
		}
	v.m = ft_read_file(v.fd);
	v.winner = ft_game(v.m);
	(v.winner == 0) ? (ft_putcolor("light red")) : (ft_putcolor("light green"));
	(v.winner == 0) ? ft_putstr("I win ;)\nMaybe next time\n")
		: (ft_putstr("You win :(\nGG\n"));
	if (close(v.fd) == -1)
	{
		ft_putcolor("red");
		ft_putstr("ERROR\n");
		exit(0);
	}
	return (0);
}
