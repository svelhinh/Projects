/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ship.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 14:11:29 by svelhinh          #+#    #+#             */
/*   Updated: 2016/06/22 16:41:47 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ship.hpp"

Ship::Ship( int const maxx, int const maxy ): _weapon(new PlasmaRifle()), _shape("   /\\   \n  (  )  \n  (  )  \n /|/\\|\\\n/_||||_\\")
{
	this->_x = maxx / 2;
	this->_y = maxy - 5;
	return;
}

Ship::Ship(Ship const & src)
{
	*this = src;
	return;
}

Ship::~Ship(void)
{
	return;
}

AWeapon	*Ship::getWeapon(void) const
{
	return this->_weapon;
}

std::string	Ship::getShape(void) const
{
	return this->_shape;
}

int			Ship::getX(void) const
{
	return this->_x;
}

int			Ship::getY(void) const
{
	return this->_y;
}

void		Ship::setX(int x)
{
	this->_x = x;
}

void		Ship::setY(int y)
{
	this->_y = y;
}

void	Ship::displayShip( void ) const
{
	std::string tmp = this->getShape();
	std::string shape[5];
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

Ship & Ship::operator=(Ship const & rhs)
{
	(void)rhs;
	return *this;
}
