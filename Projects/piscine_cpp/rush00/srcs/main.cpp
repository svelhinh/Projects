/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 11:28:53 by svelhinh          #+#    #+#             */
/*   Updated: 2016/06/23 11:56:13 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_retro.hpp"

Game	*game = NULL;
pthread_mutex_t	g_updateMutex = PTHREAD_MUTEX_INITIALIZER;

void     *update(void *ptr)
{
	(void)ptr;
	Ship	*ship = game->getShip();
	Enemy	*enemy = game->getEnemy();
	int		i = 0;

	srand(time(NULL));
	while (1)
	{
		pthread_mutex_lock(&g_updateMutex);
		clear();
		ship->displayShip();
		enemy->displayEnemy();
		if (i % 500 == 0)
		{
			int random = rand() % 2 + 1;

			int one = (random == 2) ? (1) : (-1);
			enemy->setX(enemy->getX() - one);
			enemy->setY(enemy->getY() + 1);
		}
		if (ship->getWeapon()->getShoot())
			ship->getWeapon()->shoot(ship);
		refresh();
		if (ship->getX() == enemy->getX() && ship->getY() == enemy->getY())
			exit(0);
		i++;
		pthread_mutex_unlock(&g_updateMutex);
	}
	return 0;
}

void	init_window(void)
{
	endwin();
	initscr();
	noecho();
	curs_set(FALSE);
}

void	signalInt(int sig)
{
	int			new_y, new_x;

	(void)sig;
	init_window();
	getmaxyx(stdscr, new_y, new_x);
	wresize(stdscr, new_y, new_x);
	game->setMaxX(new_x);
	game->setMaxY(new_y);
}

int		main(void)
{
	int			key;
	pthread_t   th;

	init_window();

	game = new Game();
	Ship		*ship = game->getShip();

	if (pthread_create(&th, NULL, update, (void*)0))
		return (EXIT_FAILURE);
	while(1)
	{
		key = getch();
		pthread_mutex_lock(&g_updateMutex);
		signal(SIGWINCH, signalInt);
		if (key == 65 && ship->getY() > 0)
			ship->setY(ship->getY() - 1);
		if (key == 66 && ship->getY() < game->getMaxY() - 5)
			ship->setY(ship->getY() + 1);
		if (key == 67 && ship->getX() < game->getMaxX() - 8)
			ship->setX(ship->getX() + 1);
		if (key == 68 && ship->getX() > 0)
			ship->setX(ship->getX() - 1);
		if (key == ' ')
			ship->getWeapon()->setShoot(1);
		pthread_mutex_unlock(&g_updateMutex);
	}
	endwin();

	return 0;
}
