/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 16:43:13 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/11 11:06:55 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form( void ): _gradeSign(150), _gradeExec(150)
{
	return;
}

Form::Form( std::string const name, int gradeSign, int gradeExec ): _name(name), _signed(false), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
	if (gradeSign < 1 || gradeExec < 1)
		throw Form::GradeTooHighException();
	else if (gradeSign > 150 || gradeExec > 150)
		throw Form::GradeTooLowException();
	return;
}

Form::Form( Form const & src ): _name(src.getName()), _gradeSign(src.getGradeSign()), _gradeExec(src.getGradeExec())
{
	*this = src;
	return;
}

Form::~Form( void )
{
	return;
}

std::string		Form::getName() const
{
	return this->_name;
}

int				Form::getGradeSign() const
{
	return this->_gradeSign;
}

int				Form::getGradeExec() const
{
	return this->_gradeExec;
}

bool			Form::getSigned() const
{
	return this->_signed;
}

Form & Form::operator=( Form const & rhs )
{
	_signed = rhs.getSigned();
	return *this;
}

void	Form::beSigned(Bureaucrat * bureaucrat)
{
	if (bureaucrat->getGrade() > _gradeSign)
		throw Form::GradeTooLowException();
	else
		_signed = 1;
}

std::ostream & operator << ( std::ostream & o, Form const & rhs )
{
	if (!rhs.getSigned())
		o << rhs.getName() << " form needs a bureaucrat " << rhs.getGradeSign() << " graded to sign it and a bureaucrat " << rhs.getGradeExec() << " to execute it";
	else
		o << rhs.getName() << " form is signed";
	return o;
}



Form::GradeTooHighException::GradeTooHighException()
{
	return;
}

Form::GradeTooHighException::GradeTooHighException(GradeTooHighException const &src)
{
	*this = src;
}

Form::GradeTooHighException::~GradeTooHighException() throw()
{
	return;
}

const char*		Form::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}


Form::GradeTooHighException	&Form::GradeTooHighException::operator=(GradeTooHighException const &rhs)
{
	(void)rhs;
	return *this;
}

Form::GradeTooLowException::GradeTooLowException()
{
	return;
}

Form::GradeTooLowException::GradeTooLowException(GradeTooLowException const &src)
{
	*this = src;
}

Form::GradeTooLowException::~GradeTooLowException() throw()
{
	return;
}

const char*		Form::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

Form::GradeTooLowException	&Form::GradeTooLowException::operator=(GradeTooLowException const &rhs)
{
	(void)rhs;
	return *this;
}
