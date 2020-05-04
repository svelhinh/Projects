/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 17:44:44 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/05 19:52:55 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name_, Weapon &weapon_): weapon(&weapon_), name(name_)
{
	return;
}

HumanA::HumanA(std::string name_): weapon(new Weapon("gun")), name(name_)
{
	return;
}

HumanA::~HumanA()
{
	return;
}

void	HumanA::attack() const
{
	std::cout << this->name << " attacks with his " << this->weapon->getType() << std::endl;
}

void	HumanA::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
