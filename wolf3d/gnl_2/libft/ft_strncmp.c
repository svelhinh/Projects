/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtata <vtata@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 09:32:35 by vtata             #+#    #+#             */
/*   Updated: 2015/12/02 10:21:32 by vtata            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The unsigned cast is here to fix the problem when the value "\200" is
** given to s1 (for example).
** This value is 128 in decimal base, and the signed char range is :
** -128 -> 127
** With this cast, there is no ovreflow capacity.
*/

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*c1;
	unsigned char	*c2;

	i = 0;
	c1 = (unsigned char*)s1;
	c2 = (unsigned char*)s2;
	if (n == 0)
		return (0);
	while (c1[i] == c2[i] && (c1[i] != '\0' && c2[i] != '\0'))
	{
		if (i == n - 1)
			return (c1[i] - c2[i]);
		i++;
	}
	return (c1[i] - c2[i]);
}
