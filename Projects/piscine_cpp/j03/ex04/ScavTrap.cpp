/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 14:55:31 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/07 11:32:05 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(void)
{
	return;
}

ScavTrap::ScavTrap(std::string name_): ClapTrap(name_)
{
	std::cout << "Recompiling my combat code!" << std::endl;
	hitPoints = 100;
	maxHitPoints = 100;
	energyPoints = 50;
	maxEnergyPoints = 50;
	level = 1;
	meleeAttackDamage = 20;
	rangedAttackDamage = 15;
	armorDamageReduction = 3;
	return;
}

ScavTrap::ScavTrap(ScavTrap const & src): ClapTrap(src)
{
	std::cout << "Recompiling my combat code!" << std::endl;
	*this = src;
	return;
}

ScavTrap::~ScavTrap()
{
	std::cout << "No fair! I wasn't ready." << std::endl;
	return;
}

void	ScavTrap::rangedAttack(std::string const & target)
{
	std::cout << "SC4V-TP " << name << " attacks " << target << " at range, causing " << rangedAttackDamage << " points of damage !" << std::endl;
}

void	ScavTrap::meleeAttack(std::string const & target)
{
	std::cout << "SC4V-TP " << name << " attacks " << target << " at melee, causing " << rangedAttackDamage << " points of damage !" << std::endl;
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	std::cout << "SC4V-TP " << name << " take " << amount << " points of damage !" << std::endl;
	hitPoints = (hitPoints - amount + armorDamageReduction > 0) ? (hitPoints - amount + armorDamageReduction) : (0);
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	std::cout << "SC4V-TP " << name << " repairs " << amount << " points of damage !" << std::endl;
	hitPoints = (hitPoints + amount < maxHitPoints) ? (hitPoints + amount) : (maxHitPoints);
}

void	ScavTrap::challengeNewcomer()
{
	std::string attacks[5] = {
		"You versus me! Me versus you! Either way!",
		"I will prove to you my robotic superiority!",
		"Dance battle! Or, you know... regular battle.",
		"Man versus machine! Very tiny streamlined machine!",
		"Care to have a friendly duel?"
	};

	std::cout << "\"" << attacks[rand() % 5] << "\"" << std::endl;
}



ScavTrap &	ScavTrap::operator=( ScavTrap const & rhs )
{
	ClapTrap::operator=(rhs);
	return *this;
}
