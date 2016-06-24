/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 15:17:32 by svelhinh          #+#    #+#             */
/*   Updated: 2016/06/23 16:56:28 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( std::string const name, int grade ): _name(name)
{
	try
	{
		this->_grade = this->catch_exception(grade);
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

Bureaucrat::Bureaucrat(Bureaucrat const & src)
{
	*this = src;
	return;
}

Bureaucrat::~Bureaucrat()
{
	return;
}

int				Bureaucrat::catch_exception( int grade ) const
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		return grade;
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
	try
	{
		this->_grade = this->catch_exception(this->_grade - 1);
	}
	catch (GradeTooHighException & e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (GradeTooLowException & e)
	{
		std::cout << e.what() << std::endl;
	}
}

void			Bureaucrat::dec()
{
	try
	{
		this->_grade = this->catch_exception(this->_grade + 1);
	}
	catch (GradeTooHighException & e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (GradeTooLowException & e)
	{
		std::cout << e.what() << std::endl;
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
