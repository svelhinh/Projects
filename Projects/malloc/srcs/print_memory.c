/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 17:52:34 by svelhinh          #+#    #+#             */
/*   Updated: 2017/05/11 14:43:39 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void		ft_putaddr(ptrdiff_t addr)
{
	int base;

	base = 16;
	if (addr >= base)
	{
		ft_putaddr(addr / base);
		ft_putaddr(addr % base);
	}
	else if (addr > 9)
		ft_putchar((addr % base) + 55);
	else
		ft_putchar('0' + addr % base);
}

static void		print_blocks(t_block *block, size_t *total_size)
{
	while (block)
	{
		ft_putstr("0x");
		ft_putaddr(((ptrdiff_t)block + sizeof(t_block)) & SHOW_MEMORY_FLAG);
		ft_putstr(" - 0x");
		ft_putaddr((ptrdiff_t)((void *)block + block->size) & SHOW_MEMORY_FLAG);
		ft_putstr(" : ");
		ft_putnbr(block->size - sizeof(t_block));
		ft_putendl(" octets");
		*total_size += (block->size - sizeof(t_block));
		block = block->next;
	}
}

static void		print_area(t_area *area, size_t *total_size, int type)
{
	int		already_displayed;

	already_displayed = FALSE;
	while (area)
	{
		if (area->type == type)
		{
			if (!already_displayed)
			{
				if (type == TINY)
					ft_putstr("TINY : 0x");
				else if (type == SMALL)
					ft_putstr("SMALL : 0x");
				else
					ft_putstr("LARGE : 0x");
				already_displayed = TRUE;
				ft_putaddr((ptrdiff_t)area & SHOW_MEMORY_FLAG);
				ft_putchar('\n');
			}
			print_blocks(area->block, total_size);
		}
		area = area->next;
	}
}

static void		print_areas(t_area *ptr_area, size_t *total_size)
{
	print_area(ptr_area, total_size, TINY);
	print_area(ptr_area, total_size, SMALL);
	print_area(ptr_area, total_size, LARGE);
}

void			show_alloc_mem(void)
{
	t_area	*ptr_area;
	size_t	total_size;

	ptr_area = g_begin;
	total_size = 0;
	print_areas(ptr_area, &total_size);
	ft_putstr("Total : ");
	ft_putnbr((int)total_size);
	ft_putendl(" octets");
}
