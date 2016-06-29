/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 14:11:29 by svelhinh          #+#    #+#             */
/*   Updated: 2016/06/22 16:44:34 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"

AWeapon::AWeapon(std::string const & name, int damage, char const missile): _name(name), _damage(damage), _missile(missile), _x(0), _y(0), _shoot(0)
{
	return;
}

AWeapon::AWeapon(AWeapon const & src): _missile(src.getMissile())
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

char			AWeapon::getMissile( void ) const
{
	return this->_missile;
}

int				AWeapon::getShoot( void ) const
{
	return this->_shoot;
}

void			AWeapon::setShoot( int shoot )
{
	this->_shoot = shoot;
}

int					AWeapon::getX( void ) const
{
	return this->_x;
}

void				AWeapon::setX( int x )
{
	this->_x = x;
}

int					AWeapon::getY( void ) const
{
	return this->_y;
}

void				AWeapon::setY( int y )
{
	this->_y = y;
}

AWeapon & AWeapon::operator=(AWeapon const & rhs)
{
	(void)rhs;
	return *this;
}
