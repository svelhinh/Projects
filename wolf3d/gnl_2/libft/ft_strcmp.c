/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtata <vtata@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 20:53:07 by vtata             #+#    #+#             */
/*   Updated: 2015/11/30 19:36:13 by vtata            ###   ########.fr       */
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

int		ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*c1;
	unsigned char	*c2;

	i = 0;
	c1 = (unsigned char*)s1;
	c2 = (unsigned char*)s2;
	while (c1[i] == c2[i] && (c1[i] != '\0' && c2[i] != '\0'))
		i++;
	return (c1[i] - c2[i]);
}
