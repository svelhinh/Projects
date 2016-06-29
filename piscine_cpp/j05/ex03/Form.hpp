/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 17:06:07 by svelhinh          #+#    #+#             */
/*   Updated: 2016/06/27 12:21:19 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class	Form
{
private:
    std::string const	_name;
	bool				_signed;
	int const			_grade_sign;
	int const			_grade_exec;
protected:
	virtual void	action() const = 0;
public:
    Form( std::string const name, int grade_sign, int grade_exec );
    Form( Form const & src );
    virtual ~Form();

	std::string		getName() const;
	int				getGradeSign() const;
	int				getGradeExec() const;
	bool			getSigned() const;
	void			beSigned( Bureaucrat * bc);
	void			execute( Bureaucrat const & executor );


	Form & operator = ( Form const & rhs );

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

std::ostream & operator << ( std::ostream & o, Form const & rhs );

#endif
