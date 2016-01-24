/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtata <vtata@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 09:40:43 by vtata             #+#    #+#             */
/*   Updated: 2015/12/01 23:09:36 by vtata            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		size;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 && s2)
	{
		size = ft_strlen(s1) + ft_strlen(s2) + 1;
		str = (char*)malloc(sizeof(*str) * size);
		if (str == NULL || (s1 == NULL || s2 == NULL))
			return (NULL);
		while (s1[j] != '\0')
			str[i++] = s1[j++];
		j = 0;
		while (s2[j] != '\0')
			str[i++] = s2[j++];
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
