/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 11:15:15 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/06 19:25:57 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(void)
{
	return;
}

FragTrap::FragTrap(std::string name_): hitPoints(100), maxHitPoints(100), energyPoints(100),
maxEnergyPoints(100), level(1), name(name_), meleeAttackDamage(30), rangedAttackDamage(20),
armorDamageReduction(5)
{
	std::cout << "Let's get this party started!" << std::endl;
	return;
}

FragTrap::FragTrap(FragTrap const & src)
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
	std::cout << "FR4G-TP " << name << " repair " << amount << " points of damage !" << std::endl;
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



unsigned int	FragTrap::getHitPoints() const
{
	return hitPoints;
}

unsigned int	FragTrap::getMaxHitPoints() const
{
	return maxHitPoints;
}

unsigned int	FragTrap::getEnergyPoints() const
{
	return energyPoints;
}

unsigned int	FragTrap::getMaxEnergyPoints() const
{
	return maxEnergyPoints;
}

unsigned int	FragTrap::getLevel() const
{
	return level;
}

std::string		FragTrap::getName() const
{
	return name;
}

unsigned int	FragTrap::getMeleeAttackDamage() const
{
	return meleeAttackDamage;
}

unsigned int	FragTrap::getRangedAttackDamage() const
{
	return rangedAttackDamage;
}

unsigned int	FragTrap::getArmorDamageReduction() const
{
	return armorDamageReduction;
}

void			FragTrap::setHitPoints( int const hitPoints_ )
{
	hitPoints = hitPoints_;
}

void			FragTrap::setMaxHitPoints( int const maxHitPoints_ )
{
	maxHitPoints = maxHitPoints_;
}

void			FragTrap::setEnergyPoints( int const energyPoints_ )
{
	energyPoints = energyPoints_;
}

void			FragTrap::setMaxEnergyPoints( int const maxEnergyPoints_ )
{
	maxEnergyPoints = maxEnergyPoints_;
}

void			FragTrap::setLevel( int const level_ )
{
	level = level_;
}

void			FragTrap::setName( std::string const name_ )
{
	name = name_;
}

void			FragTrap::setMeleeAttackDamage( int const meleeAttackDamage_ )
{
	meleeAttackDamage = meleeAttackDamage_;
}

void			FragTrap::setRangedAttackDamage( int const rangedAttackDamage_ )
{
	rangedAttackDamage = rangedAttackDamage_;
}

void			FragTrap::setArmorDamageReduction( int const armorDamageReduction_ )
{
	armorDamageReduction = armorDamageReduction_;
}



FragTrap &	FragTrap::operator=( FragTrap const & rhs )
{
	hitPoints = rhs.getHitPoints();
	maxHitPoints = rhs.getMaxHitPoints();
	energyPoints = rhs.getEnergyPoints();
	maxEnergyPoints = rhs.getMaxEnergyPoints();
	level = rhs.getLevel();
	name = rhs.getName();
	meleeAttackDamage = rhs.getMeleeAttackDamage();
	rangedAttackDamage = rhs.getRangedAttackDamage();
	armorDamageReduction = rhs.getArmorDamageReduction();
	return *this;
}
