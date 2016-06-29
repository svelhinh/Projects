/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 17:06:02 by svelhinh          #+#    #+#             */
/*   Updated: 2016/06/27 12:20:03 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form( std::string const name, int grade_sign, int grade_exec ): _name(name), _signed(0), _grade_sign(grade_sign), _grade_exec(grade_exec)
{
	if (grade_sign < 1 || grade_exec < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade_sign > 150 || grade_exec > 150)
		throw Bureaucrat::GradeTooLowException();
	return;
}

Form::Form(Form const & src): _grade_sign(src.getGradeSign()), _grade_exec(src.getGradeExec())
{
	*this = src;
	return;
}

Form::~Form()
{
	return;
}

std::string		Form::getName() const
{
	return this->_name;
}

int				Form::getGradeSign() const
{
	return this->_grade_sign;
}

int				Form::getGradeExec() const
{
	return this->_grade_exec;
}

bool			Form::getSigned() const
{
	return this->_signed;
}

void			Form::beSigned( Bureaucrat * bc )
{
	if (bc->getGrade() > this->_grade_sign)
		throw Form::GradeTooLowException();
	else
		this->_signed = 1;
}

Form & Form::operator=(Form const & rhs)
{
	(void)rhs;
	return *this;
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
	return ("Grade too high");
}


Form::GradeTooHighException	&Form::GradeTooHighException::operator=(GradeTooHighException const &rhs)
{
	(void)rhs;
	return (*this);
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
	return ("Grade too Low");
}

Form::GradeTooLowException	&Form::GradeTooLowException::operator=(GradeTooLowException const &rhs)
{
	(void)rhs;
	return (*this);
}
