/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 14:55:07 by svelhinh          #+#    #+#             */
/*   Updated: 2017/05/12 13:45:27 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H
# include <sys/mman.h>
# include <unistd.h>
# include "libft.h"
# include <stddef.h>

/*
**	Renvoie le multiple de 4096 le plus proche inferieur a x
*/
# define ALIGN(x) ((((x - 1) / getpagesize()) * getpagesize()) + getpagesize())

# define AREA_SIZE(at) (ALIGN(150 * (at + sizeof(t_block)) + sizeof(t_area)))
# define TINY 128
# define SMALL 1024
# define LARGE (SMALL + 1)
# define TRUE 1
# define FALSE 0
# define SHOW_MEMORY_FLAG 0xfffff

typedef struct		s_block
{
	size_t			size;
	int				free;
	struct s_block	*next;
}					t_block;

/*
**	Liste des zones contenant la taille de la zone, son type et un pointeur
**	vers la prochaine zone
*/
typedef struct		s_area
{
	size_t			size;
	int				type;
	struct s_area	*next;
	t_block			*block;
}					t_area;

t_area	*g_begin;

void				*malloc(size_t size);
void				*create_new_area(size_t size);
void				*create_first_area(size_t size);
t_area				*find_area(int type, size_t size);
t_block				*find_block(t_area *area, size_t size);
int					get_area_type(size_t size);
void				show_alloc_mem(void);

void				free(void *ptr);

void				*realloc(void *ptr, size_t size);

void				*calloc(size_t nmemb, size_t size);

#endif
