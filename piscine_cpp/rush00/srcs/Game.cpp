/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 12:10:04 by svelhinh          #+#    #+#             */
/*   Updated: 2016/06/23 11:36:34 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

Game::Game( void )
{
	getmaxyx(stdscr, this->_maxy, this->_maxx);
	this->_ship = new Ship(this->_maxx, this->_maxy);
	this->_enemy = new Enemy(this->_maxx);
	return;
}

Game::Game(Game const & src)
{
	*this = src;
	return;
}

Game::~Game(void)
{
	return;
}

Ship		*Game::getShip(void) const
{
	return this->_ship;
}

Enemy		*Game::getEnemy(void) const
{
	return this->_enemy;
}

int			Game::getMaxX(void) const
{
	return this->_maxx;
}

int			Game::getMaxY(void) const
{
	return this->_maxy;
}

void		Game::setMaxX(int maxx)
{
	this->_maxx = maxx;
}

void		Game::setMaxY(int maxy)
{
	this->_maxy = maxy;
}

Game & Game::operator=(Game const & rhs)
{
	(void)rhs;
	return *this;
}
