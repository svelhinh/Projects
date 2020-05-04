/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 19:19:03 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/11 11:19:34 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ): Form("robotomy", 72, 45), _target("moon")
{
	return;
}

RobotomyRequestForm::RobotomyRequestForm( std::string target ): Form("robotomy", 72, 45), _target(target)
{
	return;
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & src ): Form(src.getName(), src.getGradeSign(), src.getGradeExec()), _target(src.getTarget())
{
	*this = src;
	return;
}

RobotomyRequestForm::~RobotomyRequestForm( void )
{
	return;
}

std::string		RobotomyRequestForm::getTarget(void) const
{
	return _target;
}

RobotomyRequestForm & RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs )
{
	(void)rhs;
	return *this;
}

void	RobotomyRequestForm::action(void) const
{
	std::cout << "Bip bip fzzzz ,";
	(rand() % 10 + 1 < 5) ?
	(std::cout << _target << " has been robotomized successfully" << std::endl) :
	(std::cout << "Robotomization of " << _target << " has failed" << std::endl);
}
