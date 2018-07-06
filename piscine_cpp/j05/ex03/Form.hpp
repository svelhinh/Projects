/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 16:43:15 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/11 11:13:56 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Form_hpp
#define Form_hpp

#include <string>
#include <fstream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
public:
	Form( std::string const name, int gradeSign, int gradeExec );
	Form( Form const & src );
	virtual ~Form( void );

	void	beSigned(Bureaucrat * bureaucrat);
	void	execute( Bureaucrat const & executor );
	virtual void	action() const = 0;

	std::string		getName() const;
	int				getGradeSign() const;
	int				getGradeExec() const;
	bool			getSigned() const;

	Form & operator=( Form const & rhs );

	class	GradeTooHighException : public std::exception
	{
	public:
		GradeTooHighException();
		GradeTooHighException(GradeTooHighException const &rhs);
		virtual ~GradeTooHighException() throw();

		GradeTooHighException	&operator=(GradeTooHighException const &rhs);

		virtual const char* what() const throw ();
	};

	class	GradeTooLowException : public std::exception
	{
	public:
		GradeTooLowException();
		GradeTooLowException(GradeTooLowException const &rhs);
		virtual ~GradeTooLowException() throw();

		GradeTooLowException	&operator=(GradeTooLowException const &rhs);

		virtual const char* what() const throw ();
	};

private:
	Form( void );
	std::string const	_name;
	bool				_signed;
	int const			_gradeSign;
	int const			_gradeExec;
};

std::ostream & operator << ( std::ostream & o, Form const & rhs );

#endif
