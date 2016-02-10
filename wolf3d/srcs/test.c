/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 13:01:23 by svelhinh          #+#    #+#             */
/*   Updated: 2016/02/10 10:50:12 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <time.h>
#include "../libft/includes/libft.h"

int		main(void)
{
	//ft_putendl(ft_ftoa(1.000000, 2));
	double	cnt;
	double	temps;
	clock_t	end;

	cnt = 0;
	temps = 0.01;
	while (cnt < 3)
	{
		ft_putendl(ft_ftoa(cnt, 2));
		//printf("%f\n", cnt);
		end = clock() + (temps * CLOCKS_PER_SEC);
		while (clock() < end)
			;
		cnt += 0.01;
	}
	return (0);
}
