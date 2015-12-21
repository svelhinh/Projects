/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 11:46:28 by svelhinh          #+#    #+#             */
/*   Updated: 2015/12/21 13:28:39 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

void	ft_winner(int winner)
{
	(winner == 0) ? (ft_putcolor("light red")) : (ft_putcolor("light green"));
	(winner == 0) ? ft_putstr("I win ;)\nMaybe next time\n")
		: (ft_putstr("You win :(\nGG\n"));
}

int		main(int ac, char **av)
{
	t_alcu v;

	v.m = NULL;
	v.fd = 0;
	if (ac >= 2)
		if ((v.fd = open(av[1], O_RDONLY)) == -1)
		{
			ft_putcolor("red");
			ft_putstr("ERROR\n");
			return (0);
		}
	if (!(v.m = ft_read_file(v.fd)))
	{
		free(v.m);
		return (0);
	}
	v.winner = ft_game(v.m);
	ft_winner(v.winner);
	if (close(v.fd) == -1)
	{
		ft_putcolor("red");
		ft_putstr("ERROR\n");
		return (0);
	}
	return (0);
}
