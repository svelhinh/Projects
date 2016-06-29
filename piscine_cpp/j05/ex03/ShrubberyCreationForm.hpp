/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 10:40:08 by svelhinh          #+#    #+#             */
/*   Updated: 2016/06/27 11:45:29 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include <fstream>
# include "Form.hpp"

class	Form;

class	ShrubberyCreationForm : public Form
{
private:
    std::string	_target;
protected:
    void    action() const;
public:
    ShrubberyCreationForm( std::string const target );
    ShrubberyCreationForm( ShrubberyCreationForm const & src );
    virtual ~ShrubberyCreationForm();

	ShrubberyCreationForm & operator = ( ShrubberyCreationForm const & rhs );
};

#endif
