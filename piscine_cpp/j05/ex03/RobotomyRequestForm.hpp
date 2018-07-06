/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 19:19:05 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/11 11:16:22 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RobotomyRequestForm_hpp
#define RobotomyRequestForm_hpp

#include "Form.hpp"
#include <string>

class RobotomyRequestForm : public Form
{
public:
	RobotomyRequestForm( std::string target );
	RobotomyRequestForm( RobotomyRequestForm const & src );
	virtual ~RobotomyRequestForm( void );

	std::string		getTarget(void) const;

	virtual void	action() const;

	RobotomyRequestForm & operator=( RobotomyRequestForm const & rhs );

private:
	RobotomyRequestForm( void );
	std::string	_target;
};

#endif
