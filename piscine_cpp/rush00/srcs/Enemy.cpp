/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 11:27:06 by svelhinh          #+#    #+#             */
/*   Updated: 2016/06/23 11:39:54 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy( int const maxx ): _shape("   .---.\n _/__~0_\\_\n(_________)")
{
	this->_x = maxx / 2;
	this->_y = 0;
	return;
}

Enemy::Enemy(Enemy const & src)
{
	*this = src;
	return;
}

Enemy::~Enemy(void)
{
	return;
}

std::string	Enemy::getShape(void) const
{
	return this->_shape;
}

int			Enemy::getX(void) const
{
	return this->_x;
}

int			Enemy::getY(void) const
{
	return this->_y;
}

void		Enemy::setX(int x)
{
	this->_x = x;
}

void		Enemy::setY(int y)
{
	this->_y = y;
}

void	Enemy::displayEnemy( void ) const
{
	std::string tmp = this->getShape();
	std::string shape[3];
	int x = this->getX();
	int y = this->getY();

	for (int i = 0, j = 0, k = 0; i <= (int)tmp.length(); i++, k++)
	{
		if (tmp[i] == '\n' || tmp[i] == '\0')
		{
			mvprintw(y + j, x, shape[j].c_str());
			j++;
			k = -1;
		}
		else
			shape[j][k] = tmp[i];
	}
}

Enemy & Enemy::operator=(Enemy const & rhs)
{
	(void)rhs;
	return *this;
}
