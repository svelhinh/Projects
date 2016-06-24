/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 15:14:57 by svelhinh          #+#    #+#             */
/*   Updated: 2016/06/23 18:20:57 by svelhinh         ###   ########.fr       */
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
	int				catch_exception( int grade ) const;
	void			signForm( Form * form );
	void			inc();
	void			dec();


	Bureaucrat & operator = ( Bureaucrat const & rhs );

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

std::ostream & operator << ( std::ostream & o, Bureaucrat const & rhs );

#endif
