/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 16:06:35 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/07 11:48:06 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"
#include <iostream>

NinjaTrap::NinjaTrap(void)
{
	return;
}

NinjaTrap::NinjaTrap(std::string name_): ClapTrap(name_)
{
	std::cout << "Glitching weirdness is a term of endearment, right?" << std::endl;
	hitPoints = 60;
	maxHitPoints = 60;
	energyPoints = 120;
	maxEnergyPoints = 120;
	level = 1;
	meleeAttackDamage = 60;
	rangedAttackDamage = 50;
	return;
}

NinjaTrap::NinjaTrap(NinjaTrap const & src): ClapTrap(src)
{
	std::cout << "Glitching weirdness is a term of endearment, right?" << std::endl;
	*this = src;
	return;
}

NinjaTrap::~NinjaTrap()
{
	std::cout << "I'll get you next time!" << std::endl;
	return;
}

void	NinjaTrap::rangedAttack(std::string const & target)
{
	std::cout << "NINJ4-TP " << name << " attacks " << target << " at range, causing " << rangedAttackDamage << " points of damage !" << std::endl;
}

void	NinjaTrap::meleeAttack(std::string const & target)
{
	std::cout << "NINJ4-TP " << name << " attacks " << target << " at melee, causing " << rangedAttackDamage << " points of damage !" << std::endl;
}

void	NinjaTrap::takeDamage(unsigned int amount)
{
	std::cout << "NINJ4-TP " << name << " take " << amount << " points of damage !" << std::endl;
	hitPoints = (hitPoints - amount + armorDamageReduction > 0) ? (hitPoints - amount + armorDamageReduction) : (0);
}

void	NinjaTrap::beRepaired(unsigned int amount)
{
	std::cout << "NINJ4-TP " << name << " repairs " << amount << " points of damage !" << std::endl;
	hitPoints = (hitPoints + amount < maxHitPoints) ? (hitPoints + amount) : (maxHitPoints);
}

void	NinjaTrap::ninjaShoebox(FragTrap const & target)
{
	std::string attacks[5] = {
		"Hehehehe, mwaa ha ha ha, MWAA HA HA HA!",
		"Ha ha ha! Fall before your robot overlord!",
		"There is no way this ends badly!",
		"This is why I was built!",
		"Unts unts unts unts!"
	};

	std::cout << "NINJ4-TP " << name << " attacks FR4G-TP " << target.getName() << " : \"" << attacks[rand() % 5] << "\"" << std::endl;
}

void	NinjaTrap::ninjaShoebox(ScavTrap const & target)
{
	std::string attacks[5] = {
		"Hehehehe, mwaa ha ha ha, MWAA HA HA HA!",
		"Ha ha ha! Fall before your robot overlord!",
		"There is no way this ends badly!",
		"This is why I was built!",
		"Unts unts unts unts!"
	};

	std::cout << "NINJ4-TP " << name << " attacks SC4V-TP " << target.getName() << " : \"" << attacks[rand() % 5] << "\"" << std::endl;
}

void	NinjaTrap::ninjaShoebox(NinjaTrap const & target)
{
	std::string attacks[5] = {
		"Hehehehe, mwaa ha ha ha, MWAA HA HA HA!",
		"Ha ha ha! Fall before your robot overlord!",
		"There is no way this ends badly!",
		"This is why I was built!",
		"Unts unts unts unts!"
	};

	std::cout << "NINJ4-TP " << name << " attacks NINJ4-TP " << target.getName() << " : \"" << attacks[rand() % 5] << "\"" << std::endl;
}



NinjaTrap &	NinjaTrap::operator=( NinjaTrap const & rhs )
{
	ClapTrap::operator=(rhs);
	return *this;
}
