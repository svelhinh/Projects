/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 11:15:15 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/07 11:30:16 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(void)
{
	return;
}

FragTrap::FragTrap(std::string name_): ClapTrap(name_)
{
	std::cout << "Let's get this party started!" << std::endl;
	hitPoints = 100;
	maxHitPoints = 100;
	energyPoints = 100;
	maxEnergyPoints = 100;
	level = 1;
	meleeAttackDamage = 30;
	rangedAttackDamage = 20;
	armorDamageReduction = 5;
	return;
}

FragTrap::FragTrap(FragTrap const & src): ClapTrap(src)
{
	std::cout << "Let's get this party started!" << std::endl;
	*this = src;
	return;
}

FragTrap::~FragTrap()
{
	std::cout << "Argh arghargh death gurgle gurglegurgle urgh... death." << std::endl;
	return;
}

void	FragTrap::rangedAttack(std::string const & target)
{
	std::cout << "FR4G-TP " << name << " attacks " << target << " at range, causing " << rangedAttackDamage << " points of damage !" << std::endl;
}

void	FragTrap::meleeAttack(std::string const & target)
{
	std::cout << "FR4G-TP " << name << " attacks " << target << " at melee, causing " << rangedAttackDamage << " points of damage !" << std::endl;
}

void	FragTrap::takeDamage(unsigned int amount)
{
	std::cout << "FR4G-TP " << name << " take " << amount << " points of damage !" << std::endl;
	hitPoints = (hitPoints - amount + armorDamageReduction > 0) ? (hitPoints - amount + armorDamageReduction) : (0);
}

void	FragTrap::beRepaired(unsigned int amount)
{
	std::cout << "FR4G-TP " << name << " repairs " << amount << " points of damage !" << std::endl;
	hitPoints = (hitPoints + amount < maxHitPoints) ? (hitPoints + amount) : (maxHitPoints);
}

void	FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	int	neededEnergyPointsToAttack = 25;
	int	energy = energyPoints;

	std::string attacks[5] = {
		"I am a tornado of death and bullets!",
		"Wow, did I really do that?",
		"You call yourself a badass?",
		"Don't tell me that wasn't awesome!",
		"Step right up, to the Bulletnator 9000!"
	};

	if (energy - neededEnergyPointsToAttack >= 0)
	{
		energyPoints -= neededEnergyPointsToAttack;
		std::cout << "FR4G-TP " << name << " attacks " << target << " : \"" << attacks[rand() % 5] << "\"" << std::endl;
	}
	else
		std::cout << "FR4G-TP " << name << " doesn't have enough energy to attack ! He must have at least " << neededEnergyPointsToAttack << " Energy Points to attack " << target << " !"<< std::endl;
}



FragTrap &	FragTrap::operator=( FragTrap const & rhs )
{
	ClapTrap::operator=(rhs);
	return *this;
}
