/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 15:47:16 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/07 19:59:46 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"

AWeapon::AWeapon()
{
	return;
}

AWeapon::AWeapon(std::string const & name, int apcost, int damage): _name(name), _apcost(apcost), _damage(damage)
{
	return;
}

AWeapon::AWeapon(AWeapon const & src)
{
	*this = src;
	return;
}

AWeapon::~AWeapon(void)
{
	return;
}

std::string		AWeapon::getName( void ) const
{
	return _name;
}

int				AWeapon::getDamage( void ) const
{
	return _damage;
}

int				AWeapon::getAPCost( void ) const
{
	return _apcost;
}

AWeapon & AWeapon::operator=(AWeapon const & rhs)
{
	_damage = rhs.getDamage();
	_apcost = rhs.getAPCost();
	return *this;
}
