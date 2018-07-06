/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 15:36:26 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/11 10:50:57 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat( void )
{
	return;
}

Bureaucrat::Bureaucrat( std::string const name, int grade ): _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade = grade;
	return;
}

Bureaucrat::Bureaucrat( Bureaucrat const & src ): _name(src.getName())
{
	*this = src;
	return;
}

Bureaucrat::~Bureaucrat( void )
{
	return;
}

void				Bureaucrat::inc( void )
{
	if (_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	else
		_grade--;
}

void				Bureaucrat::dec( void )
{
	if (_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade++;
}

std::string const	Bureaucrat::getName( void ) const
{
	return _name;
}

int					Bureaucrat::getGrade( void ) const
{
	return _grade;
}

void	Bureaucrat::signForm(Form * form)
{
	try
	{
		form->beSigned(this);
		std::cout << this->getName() << " signs " << form->getName() << std::endl;
	}
	catch (Form::GradeTooLowException & e)
	{
		std::cout << this->getName() << " cannot sign " << form->getName() << " because " << e.what() << std::endl;
	}
}

Bureaucrat & Bureaucrat::operator=( Bureaucrat const & rhs )
{
	_grade = rhs.getGrade();
	return *this;
}

std::ostream &		operator<<( std::ostream & o, Bureaucrat const & i)
{
	o << i.getName() << std::string(", bureaucrat grade ") << std::to_string(i.getGrade());
	return o;
}



Bureaucrat::GradeTooHighException::GradeTooHighException()
{
	return;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(GradeTooHighException const &src)
{
	*this = src;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw ()
{
	return;
}

const char*		Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}


Bureaucrat::GradeTooHighException	&Bureaucrat::GradeTooHighException::operator=(GradeTooHighException const &rhs)
{
	(void)rhs;
	return *this;
}

Bureaucrat::GradeTooLowException::GradeTooLowException()
{
	return;
}

Bureaucrat::GradeTooLowException::GradeTooLowException(GradeTooLowException const &src)
{
	*this = src;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw ()
{
	return;
}

const char*		Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

Bureaucrat::GradeTooLowException	&Bureaucrat::GradeTooLowException::operator=(GradeTooLowException const &rhs)
{
	(void)rhs;
	return *this;
}
