/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 11:21:10 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/11 11:50:42 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern( void )
{
	return;
}

Intern::Intern( Intern const & src )
{
	*this = src;
	return;
}

Intern::~Intern( void )
{
	return;
}

Form	*Intern::makeForm(std::string formName, std::string target) const
{
	if (formName == "shrubberry creation")
	{
		std::cout << "Intern creates " << formName << std::endl;
		return (new ShrubberyCreationForm(target));
	}
	else if (formName == "robotomy request")
	{
		std::cout << "Intern creates " << formName << std::endl;
		return (new RobotomyRequestForm(target));
	}
	else if (formName == "presidential pardon")
	{
		std::cout << "Intern creates " << formName << std::endl;
		return (new PresidentialPardonForm(target));
	}
	else
	{
		std::cout << "Form not known" << std::endl;
		return (NULL);
	}
}

Intern & Intern::operator=( Intern const & rhs )
{
	(void)rhs;
	return *this;
}
