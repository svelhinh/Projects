/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 16:20:37 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/07 12:04:04 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperTrap.hpp"
#include <iostream>

SuperTrap::SuperTrap(void)
{
	return;
}

SuperTrap::SuperTrap(std::string name_): ClapTrap(name_), FragTrap(name_), NinjaTrap(name_)
{
	std::cout << "Look out everybody! Things are about to get awesome!" << std::endl;
	hitPoints = 100;
	maxHitPoints = 100;
	energyPoints = 120;
	maxEnergyPoints = 120;
	level = 1;
	meleeAttackDamage = 60;
	rangedAttackDamage = 20;
	armorDamageReduction = 5;

	return;
}

SuperTrap::SuperTrap(SuperTrap const & src): ClapTrap(src), FragTrap(src), NinjaTrap(src)
{
	std::cout << "Look out everybody! Things are about to get awesome!" << std::endl;
	*this = src;
	return;
}

SuperTrap::~SuperTrap()
{
	std::cout << "Crap happens." << std::endl;
	return;
}


SuperTrap &	SuperTrap::operator=( SuperTrap const & rhs )
{
	FragTrap::operator=(rhs);
	NinjaTrap::operator=(rhs);
	return *this;
}
