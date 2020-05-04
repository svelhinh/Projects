/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_areas.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 16:13:28 by svelhinh          #+#    #+#             */
/*   Updated: 2017/05/11 15:08:58 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void	*do_mmap(size_t size, int area_type)
{
	t_area	*ptr_new_area;

	if (area_type > SMALL)
	{
		if ((ptr_new_area = mmap(NULL,
		ALIGN(size + sizeof(t_block) + sizeof(t_area)),
		PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)) == MAP_FAILED)
			return (NULL);
	}
	else
	{
		if ((ptr_new_area = mmap(NULL, AREA_SIZE(area_type),
		PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)) == MAP_FAILED)
			return (NULL);
	}
	return (ptr_new_area);
}

void		*create_new_area(size_t size)
{
	t_area	*ptr_area;
	t_area	*ptr_new_area;
	int		area_type;

	area_type = get_area_type(size);
	ptr_area = g_begin;
	while (ptr_area->next)
		ptr_area = ptr_area->next;
	if (!(ptr_new_area = do_mmap(size, area_type)))
		return (NULL);
	ptr_new_area->size = size + sizeof(t_block) + sizeof(t_area);
	ptr_new_area->type = area_type;
	ptr_new_area->next = NULL;
	ptr_new_area->block = (void *)ptr_new_area + sizeof(t_area);
	ptr_new_area->block->size = size + sizeof(t_block);
	ptr_new_area->block->free = FALSE;
	ptr_new_area->block->next = NULL;
	ptr_area->next = ptr_new_area;
	return (((void *)ptr_new_area->block) + sizeof(t_block));
}

void		*create_first_area(size_t size)
{
	int	type;

	type = get_area_type(size);
	if (!(g_begin = do_mmap(size, type)))
		return (NULL);
	g_begin->size = size + sizeof(t_block) + sizeof(t_area);
	g_begin->type = type;
	g_begin->next = NULL;
	g_begin->block = (void *)g_begin + sizeof(t_area);
	g_begin->block->size = size + sizeof(t_block);
	g_begin->block->free = FALSE;
	g_begin->block->next = NULL;
	return (((void *)g_begin->block) + sizeof(t_block));
}
