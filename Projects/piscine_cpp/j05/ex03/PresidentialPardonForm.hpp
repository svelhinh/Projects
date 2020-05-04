/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 19:18:56 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/11 11:15:16 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PresidentialPardonForm_hpp
#define PresidentialPardonForm_hpp

#include "Form.hpp"
#include <string>

class PresidentialPardonForm : public Form
{
public:
	PresidentialPardonForm( std::string target );
	PresidentialPardonForm( PresidentialPardonForm const & src );
	virtual ~PresidentialPardonForm( void );

	std::string		getTarget(void) const;
	virtual void	action(void) const;

	PresidentialPardonForm & operator=( PresidentialPardonForm const & rhs );

private:
	PresidentialPardonForm( void );
	std::string	_target;
};

#endif
