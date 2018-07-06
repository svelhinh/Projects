/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 19:19:00 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/11 11:19:30 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ): Form("presidential pardon", 25, 5), _target("obama")
{
	return;
}

PresidentialPardonForm::PresidentialPardonForm( std::string target ): Form("presidential pardon", 25, 5), _target(target)
{
	return;
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const & src ): Form(src.getName(), src.getGradeSign(), src.getGradeExec()), _target(src.getTarget())
{
	*this = src;
	return;
}

PresidentialPardonForm::~PresidentialPardonForm( void )
{
	return;
}

std::string		PresidentialPardonForm::getTarget(void) const
{
	return _target;
}

PresidentialPardonForm & PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs )
{
	(void)rhs;
	return *this;
}

void	PresidentialPardonForm::action(void) const
{
	std::cout << _target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
