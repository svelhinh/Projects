/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:08:30 by svelhinh          #+#    #+#             */
/*   Updated: 2015/12/02 12:10:41 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		i2;
	int		i3;
	char	*s3;

	i = 0;
	i3 = 0;
	s3 = (char *)malloc(sizeof(char) * ft_strlen(s2) + 1);
	if (ft_memcmp(s1, s2, ft_strlen(s2)) == 0)
		return ((char *)s1);
	while (s1[i] != '\0')
	{
		i2 = 0;
		while (s2[i2++] == s1[i++])
			if (s2[i2] == '\0')
			{
				s3 = &((char *)s1)[i3];
				return (s3);
			}
		i3++;
		i = i3;
	}
	return (NULL);
}
