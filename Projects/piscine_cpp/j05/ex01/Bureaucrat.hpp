/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 15:36:23 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/10 19:05:51 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Bureaucrat_hpp
#define Bureaucrat_hpp

#include <string>
#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
public:
	Bureaucrat( std::string const name, int grade );
	Bureaucrat( Bureaucrat const & src );
	virtual ~Bureaucrat( void );

	void	signForm(Form * form);

	std::string const	getName( void ) const;
	int					getGrade( void ) const;

	void				inc( void );
	void				dec( void );

	Bureaucrat & operator=( Bureaucrat const & rhs );

	class	GradeTooHighException : public std::exception
	{
	public:
		GradeTooHighException(void);
		GradeTooHighException(GradeTooHighException const &rhs);
		virtual ~GradeTooHighException(void) throw();

		GradeTooHighException	&operator=(GradeTooHighException const &rhs);

		virtual const char* what(void) const throw ();
	};

	class	GradeTooLowException : public std::exception
	{
	public:
		GradeTooLowException(void);
		GradeTooLowException(GradeTooLowException const &rhs);
		virtual ~GradeTooLowException(void) throw();

		GradeTooLowException	&operator=(GradeTooLowException const &rhs);

		virtual const char* what(void) const throw ();
	};

private:
	Bureaucrat( void );
	std::string const	_name;
	int					_grade;
};

std::ostream &		operator<<( std::ostream & o, Bureaucrat const & i);

#endif
