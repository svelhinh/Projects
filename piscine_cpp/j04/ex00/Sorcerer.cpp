/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 13:45:42 by svelhinh          #+#    #+#             */
/*   Updated: 2016/06/20 15:36:04 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"

Sorcerer::Sorcerer(std::string name, std::string title): _name(name), _title(title)
{
	std::cout << this->getName() << ", " << this->getTitle() << ", is born !" << std::endl;
	return;
}

Sorcerer::Sorcerer(Sorcerer const & src)
{
	*this = src;
	std::cout << this->getName() << ", " << this->getTitle() << ", is born !" << std::endl;
	return;
}

Sorcerer::~Sorcerer(void)
{
	std::cout << this->getName() << ", " << this->getTitle() << ", is dead. Consequences will never be the same !" << std::endl;
	return;
}

std::string		Sorcerer::getName( void ) const
{
	return this->_name;
}

std::string		Sorcerer::getTitle( void ) const
{
	return this->_title;
}

void			Sorcerer::polymorph(Victim const & victim) const
{
	victim.getPolymorphed();
}

Sorcerer & Sorcerer::operator=(Sorcerer const & rhs)
{
	(void)rhs;
	return *this;
}

std::ostream & operator << ( std::ostream & o, Sorcerer const & rhs )
{
	o << "I am " << rhs.getName() << ", " << rhs.getTitle() << ", and I like ponies !" << std::endl;
	return o;
}
