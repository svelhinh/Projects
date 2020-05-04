/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 17:45:48 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/05 19:53:07 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name_, Weapon *weapon_): weapon(weapon_), name(name_)
{
	return;
}

HumanB::HumanB(std::string name_): weapon(new Weapon("gun")), name(name_)
{
	return;
}

HumanB::~HumanB()
{
	return;
}

void	HumanB::attack() const
{
	std::cout << this->name << " attacks with his " << this->weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
