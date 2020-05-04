/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_syms_32.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 17:39:33 by svelhinh          #+#    #+#             */
/*   Updated: 2017/08/09 16:56:00 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

static void		set_sym_values(t_nlist array_elem,
	char *stringtable, t_sym **current)
{
	char	*hex_value;
	size_t	hex_len;
	size_t	i;

	hex_value = ft_value_to_hex(array_elem.n_value);
	hex_len = ft_strlen(hex_value);
	i = 0;
	while (i < 8 - hex_len)
	{
		hex_value = ft_strjoin("0", hex_value);
		i++;
	}
	(*current)->addr = hex_value;
	(*current)->name = stringtable + array_elem.n_un.n_strx;
	(*current)->type_flag = array_elem.n_type;
	(*current)->sect_nb = array_elem.n_sect;
}

t_sym			**get_syms_32(int nsyms, int stroff, char *ptr, t_nlist *array)
{
	int				i;
	char			*stringtable;
	t_sym			**first;
	t_sym			*current;

	i = 0;
	if ((first = (t_sym **)malloc(sizeof(t_sym *))) == NULL ||
		(current = (t_sym *)malloc(sizeof(t_sym))) == NULL)
		return (NULL);
	*first = current;
	stringtable = (void *)ptr + stroff;
	while (current)
	{
		if (array[i++].n_type & N_STAB)
			continue;
		i--;
		set_sym_values(array[i], stringtable, &current);
		current->next = (++i < nsyms) ?
			((t_sym *)ft_memalloc(sizeof(t_sym))) : (NULL);
		current = current->next;
	}
	return (first);
}
