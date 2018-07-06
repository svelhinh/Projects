/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 14:38:37 by svelhinh          #+#    #+#             */
/*   Updated: 2016/08/08 14:38:38 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t i;

	i = 0;
	if (s1 != NULL && s2 != NULL)
		while (i < n)
		{
			if (((char *)s1)[i] != ((char *)s2)[i])
				return (((unsigned char *)s1)[i] - (((unsigned char *)s2)[i]));
			i++;
		}
	return (0);
}
