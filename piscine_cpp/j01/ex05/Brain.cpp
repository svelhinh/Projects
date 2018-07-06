/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 15:09:25 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/05 19:52:07 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <sstream>

Brain::Brain(int const qi_, float const weight_): qi(qi_), weight(weight_)
{
	(void)qi;
	(void)weight;
	return;
}

Brain::~Brain()
{
	return;
}

std::string	Brain::identify() const
{
	std::stringstream ss;
	ss << this;

	return ss.str();
}
