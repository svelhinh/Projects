/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 09:50:44 by svelhinh          #+#    #+#             */
/*   Updated: 2016/03/02 14:18:42 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbword(char const *s, char c)
{
	int i;
	int countword;
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

static int	ft_wordlen(char const *word, char c, int *i)
{
	while (word[*i] == c && word[*i])
		(*i)++;
	return (*i);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab_ptr;
	char	*str;
	int		start;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	str = (char*)s;
	if (!(tab_ptr = (char **)malloc(sizeof(*tab_ptr) * (ft_nbword(s, c) + 1))))
		return (NULL);
	tab_ptr[ft_nbword(s, c)] = NULL;
	while (str[i] != '\0')
	{
		start = ft_wordlen(s, c, &i);
		while (str[i] != c && str[i] != '\0')
			i++;
		(start == i) ? (tab_ptr[j] = NULL)
			: (tab_ptr[j] = ft_strsub(str, start, i - start));
		j++;
	}
	return (tab_ptr);
}
