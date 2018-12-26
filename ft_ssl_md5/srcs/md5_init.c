/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 18:23:43 by svelhinh          #+#    #+#             */
/*   Updated: 2018/07/23 19:04:45 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void	init_md5_2(unsigned int (*r)[64], unsigned int (*h)[4], int i)
{
	while (i < 48)
	{
		(*r)[i] = 4;
		(*r)[i + 1] = 11;
		(*r)[i + 2] = 16;
		(*r)[i + 3] = 23;
		i += 4;
	}
	while (i < 64)
	{
		(*r)[i] = 6;
		(*r)[i + 1] = 10;
		(*r)[i + 2] = 15;
		(*r)[i + 3] = 21;
		i += 4;
	}
	g_k = ft_memalloc(64);
	ft_test_malloc(g_k);
	i = -1;
	while (++i < 64)
		g_k[i] = floor(pow(2, 32) * fabs(sin(i + 1)));
	(*h)[0] = 0x67452301;
	(*h)[1] = 0xefcdab89;
	(*h)[2] = 0x98badcfe;
	(*h)[3] = 0x10325476;
}

void		init_md5(unsigned int (*r)[64], unsigned int (*h)[4])
{
	int	i;

	i = 0;
	while (i < 16)
	{
		(*r)[i] = 7;
		(*r)[i + 1] = 12;
		(*r)[i + 2] = 17;
		(*r)[i + 3] = 22;
		i += 4;
	}
	while (i < 32)
	{
		(*r)[i] = 5;
		(*r)[i + 1] = 9;
		(*r)[i + 2] = 14;
		(*r)[i + 3] = 20;
		i += 4;
	}
	init_md5_2(r, h, i);
}
