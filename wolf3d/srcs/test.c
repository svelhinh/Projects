/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 13:01:23 by svelhinh          #+#    #+#             */
/*   Updated: 2016/02/06 12:11:51 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#define SWIDTH 1250
#define SHEIGHT 1000
#define MWIDTH SWIDTH / 4
#define MHEIGHT SHEIGHT / 4

int		main(void)
{
	void *win;
	void *mlx;

	mlx = mlx_init();
	win = mlx_new_window(mlx, SWIDTH, SHEIGHT, "test");
	int y = 450;
	int x;
	while (y < 550)
	{
		x = 500;
		while (x < 507)
		{
			mlx_pixel_put(mlx, win, x, y, 0x550000);
			x++;
		}
		y++;
	}
	mlx_string_put(mlx, win, 500, 500, 0xAA00, "YOU WIN");
	/*mlx_string_put(mlx, win, 500, 500, 0xffffff, ":::       :::    :::::::::    :::        :::::::::  ::::::    :::::::::");
	mlx_string_put(mlx, win, 490, 520, 0xffffff, ":+:       :+:   :+:     :+:   :+:        :+:             :+:  :+:     :+:");
	mlx_string_put(mlx, win, 480, 540, 0xffffff, "+:+  +:+  +:+  +:+       +:+  +:+        +:+             +:+  +:+      +:+");
	mlx_string_put(mlx, win, 470, 560, 0xffffff, "+#+  +:+  +#+  +:+       +#+  +:+        +#+:+#     +:+#+:    +#+      +:+");
	mlx_string_put(mlx, win, 460, 580, 0xffffff, "+#+  +#+  +#+  +#+       +#+  +#+        +#+             +#+  +#+      +#+");
	mlx_string_put(mlx, win, 450, 600, 0xffffff, "#+#  #+#  #+#   #+#     #+#   #+#        #+#             #+#  #+#     #+#");
	mlx_string_put(mlx, win, 440, 620, 0xffffff, " ##### #####     #########    #########  ###        ######    #########");*/
	mlx_loop(mlx);
	return (0);
}
