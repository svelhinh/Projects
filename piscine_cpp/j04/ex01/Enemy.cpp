/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 17:15:28 by svelhinh          #+#    #+#             */
/*   Updated: 2016/06/20 17:37:45 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy(int hp, std::string const & type): _hp(hp), _type(type)
{
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

std::string		Enemy::getType( void ) const
{
	return this->_type;
}

int				Enemy::getHP( void ) const
{
	return this->_hp;
}

void			Enemy::setHP( int hp )
{
	this->_hp = hp;
}

void			Enemy::takeDamage( int nb )
{
	if (nb > 0)
		this->_hp -= nb;
}

Enemy & Enemy::operator=(Enemy const & rhs)
{
	(void)rhs;
	return *this;
}
