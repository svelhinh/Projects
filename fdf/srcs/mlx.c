/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/03 10:51:41 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/03 10:52:49 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_hook(int keycode)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

int		mouse_hook(int button, int x, int y)
{
	printf("x = %d\ny = %d\nbutton = %d\n\n", x, y, button);
	return (0);
}
