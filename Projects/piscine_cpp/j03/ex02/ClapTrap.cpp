/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 15:25:23 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/07 11:28:46 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(void)
{
	return;
}

ClapTrap::ClapTrap(std::string name_): hitPoints(0), maxHitPoints(0), energyPoints(0),
maxEnergyPoints(0), level(0), name(name_), meleeAttackDamage(0), rangedAttackDamage(0),
armorDamageReduction(0)
{
	std::cout << "Hey everybody! Check out my package!" << std::endl;
	return;
}

ClapTrap::ClapTrap(ClapTrap const & src)
{
	std::cout << "Hey everybody! Check out my package!" << std::endl;
	*this = src;
	return;
}

ClapTrap::~ClapTrap()
{
	std::cout << "I'll get you next time!" << std::endl;
	return;
}


void	ClapTrap::rangedAttack(std::string const & target)
{
	std::cout << "CL4P-TP " << name << " attacks " << target << " at range, causing " << rangedAttackDamage << " points of damage !" << std::endl;
}

void	ClapTrap::meleeAttack(std::string const & target)
{
	std::cout << "CL4P-TP " << name << " attacks " << target << " at melee, causing " << rangedAttackDamage << " points of damage !" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "CL4P-TP " << name << " take " << amount << " points of damage !" << std::endl;
	hitPoints = (hitPoints - amount + armorDamageReduction > 0) ? (hitPoints - amount + armorDamageReduction) : (0);
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "CL4P-TP " << name << " repairs " << amount << " points of damage !" << std::endl;
	hitPoints = (hitPoints + amount < maxHitPoints) ? (hitPoints + amount) : (maxHitPoints);
}



unsigned int	ClapTrap::getHitPoints() const
{
	return hitPoints;
}

unsigned int	ClapTrap::getMaxHitPoints() const
{
	return maxHitPoints;
}

unsigned int	ClapTrap::getEnergyPoints() const
{
	return energyPoints;
}

unsigned int	ClapTrap::getMaxEnergyPoints() const
{
	return maxEnergyPoints;
}

unsigned int	ClapTrap::getLevel() const
{
	return level;
}

std::string		ClapTrap::getName() const
{
	return name;
}

unsigned int	ClapTrap::getMeleeAttackDamage() const
{
	return meleeAttackDamage;
}

unsigned int	ClapTrap::getRangedAttackDamage() const
{
	return rangedAttackDamage;
}

unsigned int	ClapTrap::getArmorDamageReduction() const
{
	return armorDamageReduction;
}

void			ClapTrap::setHitPoints( int const hitPoints_ )
{
	hitPoints = hitPoints_;
}

void			ClapTrap::setMaxHitPoints( int const maxHitPoints_ )
{
	maxHitPoints = maxHitPoints_;
}

void			ClapTrap::setEnergyPoints( int const energyPoints_ )
{
	energyPoints = energyPoints_;
}

void			ClapTrap::setMaxEnergyPoints( int const maxEnergyPoints_ )
{
	maxEnergyPoints = maxEnergyPoints_;
}

void			ClapTrap::setLevel( int const level_ )
{
	level = level_;
}

void			ClapTrap::setName( std::string const name_ )
{
	name = name_;
}

void			ClapTrap::setMeleeAttackDamage( int const meleeAttackDamage_ )
{
	meleeAttackDamage = meleeAttackDamage_;
}

void			ClapTrap::setRangedAttackDamage( int const rangedAttackDamage_ )
{
	rangedAttackDamage = rangedAttackDamage_;
}

void			ClapTrap::setArmorDamageReduction( int const armorDamageReduction_ )
{
	armorDamageReduction = armorDamageReduction_;
}



ClapTrap &	ClapTrap::operator=( ClapTrap const & rhs )
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
