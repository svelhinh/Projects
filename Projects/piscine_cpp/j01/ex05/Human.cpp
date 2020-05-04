/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 15:10:07 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/04 17:49:28 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

Human::Human(): humanBrain(*(new Brain(150, 3)))
{
	return;
}

Human::~Human()
{
	return;
}

Brain	&Human::getBrain() const
{
	return this->humanBrain;
}

std::string	Human::identify() const
{
	return this->humanBrain.identify();
}
