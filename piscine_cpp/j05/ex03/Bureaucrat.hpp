/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 15:14:57 by svelhinh          #+#    #+#             */
/*   Updated: 2016/06/27 13:50:04 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include "Form.hpp"

class	Form;

class	Bureaucrat
{
private:
    std::string const	_name;
	int					_grade;
public:
    Bureaucrat( std::string const name, int grade );
    Bureaucrat( Bureaucrat const & src );
    virtual ~Bureaucrat();

	std::string		getName() const;
	int				getGrade() const;
	void			signForm( Form * form );
	void			executeForm( Form & form );
	void			inc();
	void			dec();


	Bureaucrat & operator = ( Bureaucrat const & rhs );

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
};

std::ostream & operator << ( std::ostream & o, Bureaucrat const & rhs );

#endif
