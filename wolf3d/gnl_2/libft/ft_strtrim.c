/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtata <vtata@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 10:24:03 by vtata             #+#    #+#             */
/*   Updated: 2015/12/02 09:33:04 by vtata            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s)
	{
		str = (char*)malloc(sizeof(*str) * (ft_strlen(s) + 1));
		if (str == NULL)
			return (NULL);
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i++;
		while (s[i] != '\0')
			str[j++] = s[i++];
		str[j] = '\0';
		j--;
		while (str[j] == ' ' || str[j] == '\n' || str[j] == '\t')
			j--;
		j++;
		str[j] = '\0';
		return (str);
	}
	return (NULL);
}
