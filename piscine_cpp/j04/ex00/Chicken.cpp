/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Chicken.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 14:24:54 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/07 18:35:20 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Chicken.hpp"
#include <iostream>

Chicken::Chicken()
{
	return;
}

Chicken::Chicken(std::string name_): Victim(name_)
{
	std::cout << "Cot-cot." << std::endl;
	return;
}

Chicken::Chicken(Chicken const & src): Victim(src)
{
	*this = src;
	return;
}

Chicken::~Chicken()
{
	std::cout << "Gleuark..." << std::endl;
	return;
}

void	Chicken::getPolymorphed() const
{
	std::cout << name << " has been turned into a red chicken !" << std::endl;
}

Chicken &	Chicken::operator=( Chicken const & rhs )
{
	name = rhs.getName();
	return *this;
}
