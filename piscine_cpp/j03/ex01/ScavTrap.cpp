/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 14:55:31 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/06 19:26:24 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(void)
{
	return;
}

ScavTrap::ScavTrap(std::string name_): hitPoints(100), maxHitPoints(100), energyPoints(50),
maxEnergyPoints(50), level(1), name(name_), meleeAttackDamage(20), rangedAttackDamage(15),
armorDamageReduction(3)
{
	std::cout << "Recompiling my combat code!" << std::endl;
	return;
}

ScavTrap::ScavTrap(ScavTrap const & src)
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
	std::cout << "SC4V-TP " << name << " repair " << amount << " points of damage !" << std::endl;
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



unsigned int	ScavTrap::getHitPoints() const
{
	return hitPoints;
}

unsigned int	ScavTrap::getMaxHitPoints() const
{
	return maxHitPoints;
}

unsigned int	ScavTrap::getEnergyPoints() const
{
	return energyPoints;
}

unsigned int	ScavTrap::getMaxEnergyPoints() const
{
	return maxEnergyPoints;
}

unsigned int	ScavTrap::getLevel() const
{
	return level;
}

std::string		ScavTrap::getName() const
{
	return name;
}

unsigned int	ScavTrap::getMeleeAttackDamage() const
{
	return meleeAttackDamage;
}

unsigned int	ScavTrap::getRangedAttackDamage() const
{
	return rangedAttackDamage;
}

unsigned int	ScavTrap::getArmorDamageReduction() const
{
	return armorDamageReduction;
}

void			ScavTrap::setHitPoints( int const hitPoints_ )
{
	hitPoints = hitPoints_;
}

void			ScavTrap::setMaxHitPoints( int const maxHitPoints_ )
{
	maxHitPoints = maxHitPoints_;
}

void			ScavTrap::setEnergyPoints( int const energyPoints_ )
{
	energyPoints = energyPoints_;
}

void			ScavTrap::setMaxEnergyPoints( int const maxEnergyPoints_ )
{
	maxEnergyPoints = maxEnergyPoints_;
}

void			ScavTrap::setLevel( int const level_ )
{
	level = level_;
}

void			ScavTrap::setName( std::string const name_ )
{
	name = name_;
}

void			ScavTrap::setMeleeAttackDamage( int const meleeAttackDamage_ )
{
	meleeAttackDamage = meleeAttackDamage_;
}

void			ScavTrap::setRangedAttackDamage( int const rangedAttackDamage_ )
{
	rangedAttackDamage = rangedAttackDamage_;
}

void			ScavTrap::setArmorDamageReduction( int const armorDamageReduction_ )
{
	armorDamageReduction = armorDamageReduction_;
}



ScavTrap &	ScavTrap::operator=( ScavTrap const & rhs )
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
