/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 17:47:37 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/07 20:00:22 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	return;
}

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
	return _name;
}

int					Character::getAP( void ) const
{
	return _ap;
}

AWeapon				*Character::getWeapon( void ) const
{
	return _weapon;
}

void				Character::setAP( int ap )
{
	_ap = ap;
}

void				Character::attack( Enemy *enemy )
{
	if (getAP() > 0 && getWeapon())
	{
		std::cout << getName() << " attacks " << enemy->getType() << " with a " << getWeapon()->getName() << std::endl;
		getWeapon()->attack();
		enemy->takeDamage(getWeapon()->getDamage());
		setAP( getAP() - getWeapon()->getAPCost() );
		if (enemy->getHP() <= 0)
			delete enemy;
	}
}

void				Character::equip(AWeapon *weapon)
{
	_weapon = weapon;
}

void				Character::recoverAP( void )
{
	if (getAP() + 10 < 40)
		setAP( getAP() + 10 );
	else
		setAP(40);
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
	_ap = rhs.getAP();
	_weapon = rhs.getWeapon();
	return *this;
}
