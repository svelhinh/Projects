/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 12:28:52 by svelhinh          #+#    #+#             */
/*   Updated: 2016/06/27 12:36:03 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( std::string target ): Form("RobotomyRequestForm", 145, 137), _target(target)
{
	return;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src): Form("RobotomyRequestForm", 145, 137)
{
	*this = src;
	return;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	return;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
{
	(void)rhs;
	return *this;
}


void	RobotomyRequestForm::action() const
{
	srand(time(NULL));
	(rand() % 10 + 1 < 5) ?
	(std::cout << this->_target << " has been robotomized successfully" << std::endl) :
	(std::cout << "Robotomization of " << this->_target << " has failed" << std::endl);
}
