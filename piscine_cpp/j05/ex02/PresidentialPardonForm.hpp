/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 12:39:41 by svelhinh          #+#    #+#             */
/*   Updated: 2016/06/27 12:40:19 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "Form.hpp"

class	Form;

class	PresidentialPardonForm : public Form
{
private:
    std::string	_target;
protected:
    void    action() const;
public:
    PresidentialPardonForm( std::string const target );
    PresidentialPardonForm( PresidentialPardonForm const & src );
    virtual ~PresidentialPardonForm();

	PresidentialPardonForm & operator = ( PresidentialPardonForm const & rhs );
};

#endif
