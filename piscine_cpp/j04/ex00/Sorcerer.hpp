/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 14:01:26 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/07 18:16:37 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_HPP
# define SORCERER_HPP

# include <string>
# include "Victim.hpp"

class Sorcerer
{
public:
    Sorcerer(std::string name_, std::string title_);
    ~Sorcerer();
    Sorcerer(Sorcerer const & src);

	void polymorph(Victim const &) const;


	std::string	getName() const;
	std::string	getTitle() const;


    Sorcerer &	operator=( Sorcerer const & rhs );

private:
	Sorcerer();

	std::string	name;
	std::string	title;
};

std::ostream &	operator<<( std::ostream & o, Sorcerer const & sor);

#endif
