/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 17:33:56 by svelhinh          #+#    #+#             */
/*   Updated: 2016/06/20 18:22:43 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RadScorpion.hpp"

RadScorpion::RadScorpion( void ): Enemy(80, "RadScorpion")
{
	std::cout << "* click click click *" << std::endl;
	return;
}

RadScorpion::RadScorpion(RadScorpion const & src): Enemy(80, "RadScorpion")
{
	*this = src;
	std::cout << "* click click click *" << std::endl;
	return;
}

RadScorpion::~RadScorpion(void)
{
	std::cout << "* SPROTCH *" << std::endl;
	return;
}

void			RadScorpion::takeDamage( int nb )
{
	if (nb > 0)
		this->setHP(this->getHP() - nb + 3);
}

RadScorpion & RadScorpion::operator=(RadScorpion const & rhs)
{
	(void)rhs;
	return *this;
}
