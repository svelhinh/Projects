/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 16:31:26 by svelhinh          #+#    #+#             */
/*   Updated: 2016/06/20 17:42:52 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PowerFist.hpp"

PowerFist::PowerFist( void ): AWeapon("Power Fist", 8, 50)
{
	return;
}

PowerFist::PowerFist(PowerFist const & src): AWeapon("Power Fist", 8, 50)
{
	*this = src;
	return;
}

PowerFist::~PowerFist(void)
{
	return;
}

void	PowerFist::attack( void ) const
{
	std::cout << "* pschhh... SBAM! *" << std::endl;
}

PowerFist & PowerFist::operator=(PowerFist const & rhs)
{
	(void)rhs;
	return *this;
}
