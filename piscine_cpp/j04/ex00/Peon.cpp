/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 15:31:08 by svelhinh          #+#    #+#             */
/*   Updated: 2016/06/20 15:39:39 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Peon.hpp"

Peon::Peon(std::string name): Victim(name)
{
	std::cout << "Zog zog." << std::endl;
	return;
}

Peon::Peon(Peon const & src): Victim(src)
{
	*this = src;
	std::cout << "Zog zog." << std::endl;
	return;
}

Peon::~Peon(void)
{
	std::cout << "Bleuark..." << std::endl;
	return;
}

void	Peon::getPolymorphed( void ) const
{
	std::cout << this->getName() << " has been turned into a pink pony !" << std::endl;
}

Peon & Peon::operator=(Peon const & rhs)
{
	(void)rhs;
	return *this;
}
