/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtata <vtata@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 12:47:47 by vtata             #+#    #+#             */
/*   Updated: 2015/11/30 19:04:16 by vtata            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t i;
	size_t j;
	size_t result;
	size_t size;

	i = 0;
	j = 0;
	size = n - (ft_strlen(dst)) - 1;
	result = (size_t)(ft_strlen(dst) + ft_strlen(src));
	if (src == NULL)
		return (-1);
	if (n <= ft_strlen(dst))
		return (ft_strlen(src) + n);
	while (dst[i] != '\0')
		i++;
	while (src[j] != '\0' && j < size)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (result);
}
