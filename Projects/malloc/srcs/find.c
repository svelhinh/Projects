/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 16:12:51 by svelhinh          #+#    #+#             */
/*   Updated: 2017/05/11 14:40:37 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

/*
**	Cherche une zone de type "type" dans laquelle il y a encore assez d'espace
**	pour allouer une taille de "size" donnees
*/

t_area	*find_area(int type, size_t size)
{
	t_area	*ptr_area;
	int		free_area;
	size_t	area_size;

	ptr_area = g_begin;
	free_area = FALSE;
	area_size = AREA_SIZE(type);
	if (!ptr_area->next && ptr_area->type == type &&
		size <= area_size - ptr_area->size)
		return (ptr_area);
	while (ptr_area->next)
	{
		if (ptr_area->type == type &&
			size + sizeof(t_block) <= area_size - ptr_area->size)
		{
			free_area = TRUE;
			break ;
		}
		ptr_area = ptr_area->next;
	}
	return ((free_area) ? (ptr_area) : (NULL));
}

/*
** Cherche un bloc libre dans une zone, s'il n'en trouve pas, alors il
** renvoie un pointeur sur le bloc precedent
*/

t_block	*find_block(t_area *area, size_t size)
{
	t_block	*ptr_block;
	t_block	*ptr_last_block;
	int		free_block;

	ptr_block = area->block;
	free_block = FALSE;
	while (ptr_block)
	{
		if (ptr_block->free && ptr_block->size - sizeof(t_block) >= size)
		{
			free_block = TRUE;
			break ;
		}
		ptr_last_block = ptr_block;
		ptr_block = ptr_block->next;
	}
	return ((free_block) ? (ptr_block) : (ptr_last_block));
}
