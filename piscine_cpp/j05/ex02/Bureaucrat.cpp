/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 15:17:32 by svelhinh          #+#    #+#             */
/*   Updated: 2016/06/27 13:49:43 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( std::string const name, int grade ): _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
	return;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src)
{
	*this = src;
	return;
}

Bureaucrat::~Bureaucrat()
{
	return;
}

std::string		Bureaucrat::getName() const
{
	return this->_name;
}

int				Bureaucrat::getGrade() const
{
	return this->_grade;
}

void			Bureaucrat::inc()
{
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade--;
}

void			Bureaucrat::dec()
{
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade++;
}

void			Bureaucrat::signForm( Form * form )
{
	try
	{
		form->beSigned(this);
		std::cout << this->getName() << " signs " << form->getName() << std::endl;
	}
	catch (Form::GradeTooLowException & e)
	{
		std::cout << this->getName() << " can't sign " << form->getName() << " because " << e.what() << std::endl;
	}
}

void			Bureaucrat::executeForm( Form & form )
{
	try
	{
		form.execute(*this);
		std::cout << this->_name << " executes " << form.getName() << std::endl;
	}
	catch (Form::GradeTooLowException & e)
	{
		std::cout << this->_name << " can't execute  " << form.getName() << " because " << e.what() << std::endl;
	}
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs)
{
	(void)rhs;
	return *this;
}

std::ostream & operator << ( std::ostream & o, Bureaucrat const & rhs )
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
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

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw()
{
	return;
}

const char*		Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}


Bureaucrat::GradeTooHighException	&Bureaucrat::GradeTooHighException::operator=(GradeTooHighException const &rhs)
{
	(void)rhs;
	return (*this);
}

Bureaucrat::GradeTooLowException::GradeTooLowException()
{
	return;
}

Bureaucrat::GradeTooLowException::GradeTooLowException(GradeTooLowException const &src)
{
	*this = src;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw()
{
	return;
}

const char*		Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too Low");
}

Bureaucrat::GradeTooLowException	&Bureaucrat::GradeTooLowException::operator=(GradeTooLowException const &rhs)
{
	(void)rhs;
	return (*this);
}
