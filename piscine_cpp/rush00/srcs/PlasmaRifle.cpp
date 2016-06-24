/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 16:19:09 by svelhinh          #+#    #+#             */
/*   Updated: 2016/06/23 11:43:27 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle( void ): AWeapon("Plasma Rifle", 1, 'o')
{
	return;
}

PlasmaRifle::PlasmaRifle(PlasmaRifle const & src): AWeapon("Plasma Rifle", 1, 'o')
{
	*this = src;
	return;
}

PlasmaRifle::~PlasmaRifle(void)
{
	return;
}

void	PlasmaRifle::shoot( Ship *ship )
{
	static int	i = 0;

	if (!i)
	{
		this->setX(ship->getX() + 3);
		this->setY(ship->getY() - 1);
		i++;
	}
	mvprintw(this->getY(), this->getX(), "%c", this->getMissile());
	mvprintw(this->getY(), this->getX() + 1, "%c", this->getMissile());
	if (i % 100 == 0)
		this->setY(this->getY() - 1);
	refresh();
	if (this->getY() <= 0)
	{
		i = -1;
		this->setShoot(0);
	}
	i++;
}

PlasmaRifle & PlasmaRifle::operator=(PlasmaRifle const & rhs)
{
	(void)rhs;
	return *this;
}
