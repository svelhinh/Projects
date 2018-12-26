/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_64_endian.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 18:35:13 by svelhinh          #+#    #+#             */
/*   Updated: 2018/07/23 19:00:05 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_swap_64_endian(long long nb)
{
	nb = ((nb << 8) & 0xFF00FF00FF00FF00ULL) |
		((nb >> 8) & 0x00FF00FF00FF00FFULL);
	nb = ((nb << 16) & 0xFFFF0000FFFF0000ULL) |
		((nb >> 16) & 0x0000FFFF0000FFFFULL);
	return ((nb << 32) | ((nb >> 32) & 0xFFFFFFFFULL));
}
