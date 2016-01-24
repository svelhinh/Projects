/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtata <vtata@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:17:36 by vtata             #+#    #+#             */
/*   Updated: 2015/12/07 13:02:33 by vtata            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

void		ft_memdel(void **ap)
{
	if (*ap != NULL)
		free(*ap);
	if (*ap != NULL)
		*ap = NULL;
}
