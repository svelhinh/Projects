/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 11:21:13 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/11 11:49:28 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Intern_hpp
#define Intern_hpp

#include "Form.hpp"
#include <string>

class Intern
{
public:
	Intern( void );
	Intern( Intern const & src );
	virtual ~Intern( void );

	Form	*makeForm(std::string formName, std::string target) const;

	Intern & operator=( Intern const & rhs );
};

#endif
