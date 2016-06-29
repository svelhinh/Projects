/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 13:59:40 by svelhinh          #+#    #+#             */
/*   Updated: 2016/06/27 14:17:57 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	return;
}

Intern::Intern(Intern const & src)
{
	*this = src;
	return;
}

Intern::~Intern()
{
	return;
}

Intern & Intern::operator=(Intern const & rhs)
{
	(void)rhs;
	return *this;
}

Form    *Intern::makeForm(std::string name, std::string target)
{
	if (name == "shrubberry creation")
		return (new ShrubberyCreationForm(target));
	else if (name == "robotomy request")
		return (new RobotomyRequestForm(target));
	else if (name == "presidential pardon")
		return (new PresidentialPardonForm(target));
	else
	{
		std::cout << "Form not known" << std::endl;
		return (NULL);
	}
}
