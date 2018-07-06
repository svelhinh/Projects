/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 14:01:09 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/07 18:12:04 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"
#include <iostream>

Sorcerer::Sorcerer()
{
	return;
}

Sorcerer::Sorcerer(std::string name_, std::string title_): name(name_), title(title_)
{
	std::cout << name << ", " << title << ", is born !" << std::endl;
	return;
}

Sorcerer::Sorcerer(Sorcerer const & src)
{
	*this = src;
	return;
}

Sorcerer::~Sorcerer()
{
	std::cout << name << ", " << title << ", is dead. Consequences will never be the same !" << std::endl;
	return;
}

void	Sorcerer::polymorph(Victim const & src) const
{
	src.getPolymorphed();
}


Sorcerer &	Sorcerer::operator=( Sorcerer const & rhs )
{
	name = rhs.getName();
	title = rhs.getTitle();
	return *this;
}

std::string Sorcerer::getName() const
{
    return name;
}

std::string Sorcerer::getTitle() const
{
    return title;
}

std::ostream &	operator<<( std::ostream & o, Sorcerer const & sor)
{
	o << "I am " << sor.getName() << ", " << sor.getTitle() << ", and I like ponies !" << std::endl;

	return o;
}
