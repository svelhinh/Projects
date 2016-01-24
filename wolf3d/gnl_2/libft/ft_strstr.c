/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtata <vtata@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:43:34 by vtata             #+#    #+#             */
/*   Updated: 2015/12/03 22:04:44 by vtata            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;
	int		retry;
	char	*str;

	i = 0;
	j = 0;
	retry = 0;
	str = (char*)&s1[0];
	if (s2[0] == '\0')
		return (str);
	while (s1[i] != '\0')
	{
		while (s1[i] != s2[j] && s1[i] != '\0')
			i++;
		str = (char*)&s1[i];
		while (s1[i++] == s2[j++])
		{
			if (s2[j] == '\0')
				return (str);
		}
		j = 0;
		i = retry++;
	}
	return (NULL);
}
