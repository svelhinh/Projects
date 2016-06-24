/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 17:06:07 by svelhinh          #+#    #+#             */
/*   Updated: 2016/06/23 18:21:11 by svelhinh         ###   ########.fr       */
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
public:
    Form( std::string const name, int grade_sign, int grade_exec );
    Form( Form const & src );
    virtual ~Form();

	std::string		getName() const;
	int				getGradeSign() const;
	int				getGradeExec() const;
	bool			getSigned() const;
	int				catch_exception( int grade ) const;
	void			beSigned( Bureaucrat * bc);


	Form & operator = ( Form const & rhs );

	class	GradeTooHighException : public std::exception
	{
	public:
		virtual const char* what() const throw()
		{
			return ("Grade too high");
		}
	};

	class	GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what() const throw()
		{
			return ("Grade too low");
		}
	};
};

std::ostream & operator << ( std::ostream & o, Form const & rhs );

#endif
