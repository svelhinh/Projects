/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 14:32:13 by svelhinh          #+#    #+#             */
/*   Updated: 2016/06/20 15:39:36 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Victim.hpp"

Victim::Victim(std::string name): _name(name)
{
	std::cout << "Some random victim called " << this->getName() << " just popped !" << std::endl;
	return;
}

Victim::Victim(Victim const & src)
{
	*this = src;
	std::cout << "Some random victim called " << this->getName() << " just popped !" << std::endl;
	return;
}

Victim::~Victim(void)
{
	std::cout << "Victim " << this->getName() << " just died for no apparent reason !" << std::endl;
	return;
}

std::string		Victim::getName( void ) const
{
	return this->_name;
}

void	Victim::getPolymorphed( void ) const
{
	std::cout << this->getName() << " has been turned into a cute little sheep !" << std::endl;
}

Victim & Victim::operator=(Victim const & rhs)
{
	(void)rhs;
	return *this;
}

std::ostream & operator << ( std::ostream & o, Victim const & rhs )
{
	o << "I am " << rhs.getName() << " and i like otters !" << std::endl;
	return o;
}
