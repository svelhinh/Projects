/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 13:29:21 by svelhinh          #+#    #+#             */
/*   Updated: 2017/08/09 13:56:02 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "nm.h"

static void		split_front_back(t_sym *source, t_sym **front_ref,
	t_sym **back_ref)
{
	t_sym	*fast;
	t_sym	*slow;

	if (source == NULL || source->next == NULL)
	{
		*front_ref = source;
		*back_ref = NULL;
	}
	else
	{
		slow = source;
		fast = source->next;
		while (fast != NULL)
		{
			fast = fast->next;
			if (fast != NULL)
			{
				slow = slow->next;
				fast = fast->next;
			}
		}
		*front_ref = source;
		*back_ref = slow->next;
		slow->next = NULL;
	}
}

static t_sym	*sorted_merge(t_sym *a, t_sym *b)
{
	t_sym *result;

	result = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (ft_strcmp(a->name, b->name) <= 0)
	{
		result = a;
		result->next = sorted_merge(a->next, b);
	}
	else
	{
		result = b;
		result->next = sorted_merge(a, b->next);
	}
	return (result);
}

void			merge_sort(t_sym **head_ref)
{
	t_sym	*head;
	t_sym	*a;
	t_sym	*b;

	head = *head_ref;
	if (head == NULL || head->next == NULL)
		return ;
	split_front_back(head, &a, &b);
	merge_sort(&a);
	merge_sort(&b);
	*head_ref = sorted_merge(a, b);
}
