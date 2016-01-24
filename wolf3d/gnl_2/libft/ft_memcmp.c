/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtata <vtata@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:18:58 by vtata             #+#    #+#             */
/*   Updated: 2015/12/07 14:21:11 by vtata            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	if (!s1 || !s2)
		return (0);
	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	while (str1[i] == str2[i] && i < n)
		i++;
	if (i == n && str1[i - 1] == str2[i - 1])
		return (0);
	return (str1[i] - str2[i]);
}
