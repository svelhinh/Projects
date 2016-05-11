/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 11:08:19 by svelhinh          #+#    #+#             */
/*   Updated: 2016/05/11 14:43:11 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_exit(char *s)
{
	ft_putstr_fd(s, 2);
	exit(0);
}

int		main(int ac, char **av)
{
	t_env rt;

	if (ac != 2)
		(ac > 2) ? (ft_exit("\033[31mToo many parameters\n")) :
			(ft_exit("\033[31mNot enough parameters\n"));
	if (av[1][ft_strlen(av[1]) - 3] == '.' && av[1][ft_strlen(av[1]) - 2] == 'r'
			&& av[1][ft_strlen(av[1]) - 1] == 't')
		create_window(av[1]);
	else
		ft_exit("\033[31mFiles must have .rt extension\n");
	return (0);
}
