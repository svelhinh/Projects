/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 15:47:16 by svelhinh          #+#    #+#             */
/*   Updated: 2016/06/20 16:03:50 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"

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
	return this->_name;
}

int				AWeapon::getDamage( void ) const
{
	return this->_damage;
}

int				AWeapon::getAPCost( void ) const
{
	return this->_apcost;
}

AWeapon & AWeapon::operator=(AWeapon const & rhs)
{
	(void)rhs;
	return *this;
}
