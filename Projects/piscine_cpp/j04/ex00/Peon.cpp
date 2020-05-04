/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 14:24:54 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/07 18:22:18 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Peon.hpp"
#include <iostream>

Peon::Peon()
{
	return;
}

Peon::Peon(std::string name_): Victim(name_)
{
	std::cout << "Zog zog." << std::endl;
	return;
}

Peon::Peon(Peon const & src): Victim(src)
{
	*this = src;
	return;
}

Peon::~Peon()
{
	std::cout << "Bleuark..." << std::endl;
	return;
}

void	Peon::getPolymorphed() const
{
	std::cout << name << " has been turned into a pink pony !" << std::endl;
}

Peon &	Peon::operator=( Peon const & rhs )
{
	name = rhs.getName();
	return *this;
}
