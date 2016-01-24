/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtata <vtata@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 11:00:40 by vtata             #+#    #+#             */
/*   Updated: 2015/12/07 09:36:53 by vtata            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_countword(char const *s, char c)
{
	int	i;
	int	countword;
	int firstletter;

	i = 0;
	countword = 0;
	firstletter = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && firstletter == 0)
		{
			countword++;
			firstletter++;
		}
		if (s[i] == c && firstletter > 0)
			firstletter = 0;
		i++;
	}
	return (countword);
}

static void		ft_line_saver(char *s, char *c, int *i, int *start)
{
	while (s[*i] == *c && s[*i] != '\0')
		*i = *i + 1;
	*start = *i;
	while (s[*i] != *c && s[*i] != '\0')
		*i = *i + 1;
}

char			**ft_strsplit(char const *s, char c)
{
	char				**tab_ptr;
	char				*str;
	int					start;
	int					i;
	int					j;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	str = (char*)s;
	tab_ptr = (char**)malloc(sizeof(*tab_ptr) * (ft_countword(s, c) + 1));
	if (tab_ptr == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		ft_line_saver(str, &c, &i, &start);
		if (start == i)
			tab_ptr[j] = NULL;
		else
			tab_ptr[j] = ft_strsub(str, start, i - start);
		j++;
	}
	tab_ptr[ft_countword(s, c)] = NULL;
	return (tab_ptr);
}
