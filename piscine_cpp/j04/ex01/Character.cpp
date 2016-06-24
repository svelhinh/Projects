/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 17:47:37 by svelhinh          #+#    #+#             */
/*   Updated: 2016/06/20 18:28:53 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character( std::string const & name ): _name(name), _ap(40), _weapon(NULL)
{
	return;
}

Character::Character(Character const & src)
{
	*this = src;
	return;
}

Character::~Character(void)
{
	return;
}

std::string			Character::getName( void ) const
{
	return this->_name;
}

int					Character::getAP( void ) const
{
	return this->_ap;
}

AWeapon				*Character::getWeapon( void ) const
{
	return this->_weapon;
}

void				Character::setAP( int ap )
{
	this->_ap = ap;
}

void				Character::attack( Enemy *enemy )
{
	if (this->getAP() > 0 && this->getWeapon())
	{
		std::cout << this->getName() << " attacks " << enemy->getType() << " with a " << this->getWeapon()->getName() << std::endl;
		this->getWeapon()->attack();
		enemy->takeDamage(this->getWeapon()->getDamage());
		this->setAP( this->getAP() - this->getWeapon()->getAPCost() );
		if (enemy->getHP() <= 0)
			delete enemy;
	}
}

void				Character::equip(AWeapon *weapon)
{
	this->_weapon = weapon;
}

void				Character::recoverAP( void )
{
	if (this->getAP() + 10 < 40)
		this->setAP( this->getAP() + 10 );
	else
		this->setAP(40);
}

std::ostream & operator << ( std::ostream & o, Character const & rhs )
{
	if (rhs.getWeapon())
		o << rhs.getName() << " has " << rhs.getAP() << " AP and wields a " << rhs.getWeapon()->getName() << std::endl;
	else
		o << rhs.getName() << " has " << rhs.getAP() << " AP and is unarmed" << std::endl;
	return o;
}

Character & Character::operator=(Character const & rhs)
{
	(void)rhs;
	return *this;
}
