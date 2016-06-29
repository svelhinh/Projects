/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 12:29:13 by svelhinh          #+#    #+#             */
/*   Updated: 2016/06/27 12:40:06 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "Form.hpp"

class	Form;

class	RobotomyRequestForm : public Form
{
private:
    std::string	_target;
protected:
    void    action() const;
public:
    RobotomyRequestForm( std::string const target );
    RobotomyRequestForm( RobotomyRequestForm const & src );
    virtual ~RobotomyRequestForm();

	RobotomyRequestForm & operator = ( RobotomyRequestForm const & rhs );
};

#endif
