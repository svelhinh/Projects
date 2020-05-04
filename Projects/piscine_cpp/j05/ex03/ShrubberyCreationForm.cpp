/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 19:19:07 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/11 11:19:39 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ): Form("shruberry", 145, 137), _target("home")
{
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ): Form("shruberry", 145, 137), _target(target)
{
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & src ): Form(src.getName(), src.getGradeSign(), src.getGradeExec()), _target(src.getTarget())
{
	*this = src;
	return;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
	return;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
{
	(void)rhs;
	return *this;
}

std::string		ShrubberyCreationForm::getTarget(void) const
{
	return _target;
}

void	ShrubberyCreationForm::action( void ) const
{
	std::ofstream	outFile;

	outFile.open(_target + "_shrubbery");
	for (int i = 0; i < 5; i++)
		outFile << "       _-_\n    /~~   ~~\\\n /~~         ~~\\\n{               }\n \\  _-     -_  /\n   ~  \\\\ //  ~\n_- -   | | _- _\n  _ -  | |   -_\n      // \\\\" << std::endl;
	outFile.close();
}
