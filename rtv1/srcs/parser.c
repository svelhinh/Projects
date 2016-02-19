/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 18:12:29 by svelhinh          #+#    #+#             */
/*   Updated: 2016/02/19 11:13:50 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	parsing_file(char *file, t_rt *rt)
{
	int fd;

	(void)rt;
	if ((fd = open(file, O_RDONLY) == -1))
		ft_exit("This scene doesn't exist");
}
