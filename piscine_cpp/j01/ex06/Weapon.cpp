/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 17:47:26 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/04 18:46:45 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

#include <iostream>

Weapon::Weapon(std::string type_): type(type_)
{
	return;
}

Weapon::~Weapon()
{
	return;
}

std::string const	&Weapon::getType() const
{
	return this->type;
}

void		Weapon::setType(std::string type)
{
	this->type = type;
}
