/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Goat.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 14:24:54 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/07 18:32:29 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Goat.hpp"
#include <iostream>

Goat::Goat()
{
	return;
}

Goat::Goat(std::string name_): Victim(name_)
{
	std::cout << "Bêêêêêêêêêêê." << std::endl;
	return;
}

Goat::Goat(Goat const & src): Victim(src)
{
	*this = src;
	return;
}

Goat::~Goat()
{
	std::cout << "Mêêêêark..." << std::endl;
	return;
}

void	Goat::getPolymorphed() const
{
	std::cout << name << " has been turned into a white sheep !" << std::endl;
}

Goat &	Goat::operator=( Goat const & rhs )
{
	name = rhs.getName();
	return *this;
}
