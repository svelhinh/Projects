/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 14:24:54 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/07 18:17:46 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Victim.hpp"
#include <iostream>

Victim::Victim()
{
	return;
}

Victim::Victim(std::string name_): name(name_)
{
	std::cout << "Some random victim called " << name << " just popped !" << std::endl;
	return;
}

Victim::Victim(Victim const & src)
{
	*this = src;
	return;
}

Victim::~Victim()
{
	std::cout << "Victim " << name << " just died for no apparent reason !" << std::endl;
	return;
}

void	Victim::getPolymorphed() const
{
	std::cout << name << " has been turned into a cute little sheep !" << std::endl;
}

Victim &	Victim::operator=( Victim const & rhs )
{
	name = rhs.getName();
	return *this;
}

std::string Victim::getName() const
{
	return name;
}

std::ostream &	operator<<( std::ostream & o, Victim const & vic)
{
	o << "I'm " << vic.getName() << " and I like otters !" << std::endl;

	return o;
}
