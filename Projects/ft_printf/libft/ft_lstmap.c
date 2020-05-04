/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 14:37:58 by svelhinh          #+#    #+#             */
/*   Updated: 2016/08/08 14:37:59 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *list;
	t_list *new;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	new = f(lst);
	list = new;
	while (lst->next)
	{
		if (!(new->next = ((t_list *)malloc(sizeof(t_list)))))
			return (NULL);
		lst = lst->next;
		new->next = f(lst);
		new = new->next;
	}
	return (list);
}
