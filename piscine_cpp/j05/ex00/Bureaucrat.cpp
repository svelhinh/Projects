/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 15:36:26 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/11 10:50:31 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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



Bureaucrat::GradeTooHighException::GradeTooHighException( void )
{
	return;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(GradeTooHighException const &src)
{
	*this = src;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException( void ) throw ()
{
	return;
}

const char*		Bureaucrat::GradeTooHighException::what( void ) const throw( void )
{
	return "Grade too high";
}


Bureaucrat::GradeTooHighException	&Bureaucrat::GradeTooHighException::operator=(GradeTooHighException const &rhs)
{
	(void)rhs;
	return *this;
}

Bureaucrat::GradeTooLowException::GradeTooLowException( void )
{
	return;
}

Bureaucrat::GradeTooLowException::GradeTooLowException(GradeTooLowException const &src)
{
	*this = src;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException( void ) throw ()
{
	return;
}

const char*		Bureaucrat::GradeTooLowException::what( void ) const throw()
{
	return "Grade too low";
}

Bureaucrat::GradeTooLowException	&Bureaucrat::GradeTooLowException::operator=(GradeTooLowException const &rhs)
{
	(void)rhs;
	return *this;
}
