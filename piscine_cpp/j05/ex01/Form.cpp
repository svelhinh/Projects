/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 17:06:02 by svelhinh          #+#    #+#             */
/*   Updated: 2016/06/23 18:22:36 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form( std::string const name, int grade_sign, int grade_exec ): _name(name), _signed(0), _grade_sign(grade_sign), _grade_exec(grade_exec)
{
	try
	{
		this->catch_exception(grade_sign);
		this->catch_exception(grade_exec);
	}
	catch (GradeTooHighException & e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (GradeTooLowException & e)
	{
		std::cout << e.what() << std::endl;
	}
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

int				Form::catch_exception( int grade ) const
{
	if (grade < 1)
		throw Form::GradeTooHighException();
	else if (grade > 150)
		throw Form::GradeTooLowException();
	else
		return grade;
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
