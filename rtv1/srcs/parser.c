/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 18:12:29 by svelhinh          #+#    #+#             */
/*   Updated: 2016/02/18 18:26:38 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	parsing_file(char *file, t_rt *rt)
{
	int fd;

	if ((fd = open(file, O_RDONLY) == -1))
		ft_exit("This scene doesn't exist");
}
