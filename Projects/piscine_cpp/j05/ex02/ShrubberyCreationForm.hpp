/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 19:19:09 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/11 11:16:26 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ShrubberyCreationForm_hpp
#define ShrubberyCreationForm_hpp

#include "Form.hpp"
#include <string>

class ShrubberyCreationForm : public Form
{
public:
	ShrubberyCreationForm( std::string target );
	ShrubberyCreationForm( ShrubberyCreationForm const & src );
	virtual ~ShrubberyCreationForm( void );

	std::string		getTarget(void) const;

	ShrubberyCreationForm & operator=( ShrubberyCreationForm const & rhs );

	virtual void	action( void ) const;

private:
	ShrubberyCreationForm( void );
	std::string	_target;
};

#endif
