/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 17:27:02 by svelhinh          #+#    #+#             */
/*   Updated: 2016/06/20 18:23:05 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperMutant.hpp"

SuperMutant::SuperMutant( void ): Enemy(170, "Super Mutant")
{
	std::cout << "Gaaah. Me want smash heads !" << std::endl;
	return;
}

SuperMutant::SuperMutant(SuperMutant const & src): Enemy(170, "Super Mutant")
{
	*this = src;
	std::cout << "Gaaah. Me want smash heads !" << std::endl;
	return;
}

SuperMutant::~SuperMutant(void)
{
	std::cout << "Aaargh ..." << std::endl;
	return;
}

void			SuperMutant::takeDamage( int nb )
{
	if (nb > 0)
		this->setHP(this->getHP() - nb + 3);
}

SuperMutant & SuperMutant::operator=(SuperMutant const & rhs)
{
	(void)rhs;
	return *this;
}
