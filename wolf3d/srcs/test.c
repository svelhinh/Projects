/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 13:01:23 by svelhinh          #+#    #+#             */
/*   Updated: 2016/02/09 19:26:49 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <time.h>
#include "../libft/includes/libft.h"

int		main(void)
{
	/*float yo = 0.000976 * 10;

	printf("%f\n", yo);*/
	ft_putendl(ft_ftoa(67.009761, 6));
	/*double	cnt;
	double	temps;
	clock_t	end;

	cnt = 0;
	temps = 0.0001;
	while (cnt < 3)
	{
		ft_putendl(ft_ftoa(cnt, 4));
		//printf("%f\n", cnt);
		end = clock() + (temps * CLOCKS_PER_SEC);
		while (clock() < end)
			;
		cnt += 0.0001;
	}*/
	return (0);
}
