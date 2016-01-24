/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtata <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 17:47:27 by vtata             #+#    #+#             */
/*   Updated: 2015/12/07 12:32:54 by vtata            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *tmp;
	t_list *ret;

	tmp = (t_list*)malloc(sizeof(*tmp));
	if (tmp == NULL)
		return (NULL);
	tmp = f(lst);
	ret = tmp;
	if (lst && f)
	{
		while (lst->next != NULL)
		{
			tmp->next = (t_list*)malloc(sizeof(*tmp));
			lst = lst->next;
			tmp->next = f(lst);
			tmp = tmp->next;
		}
	}
	return (ret);
}
