/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 15:28:01 by svelhinh          #+#    #+#             */
/*   Updated: 2016/06/20 15:50:21 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_HPP
# define SORCERER_HPP
# include <iostream>
# include <cmath>
#include "Victim.hpp"

class Sorcerer
{
private:
	const std::string _name;
	const std::string _title;
	Sorcerer();

public:
	Sorcerer( std::string name, std::string title );
	Sorcerer( Sorcerer const & src );
	virtual ~Sorcerer( void );

	std::string		getName( void ) const;
	std::string		getTitle( void ) const;

	void			polymorph(Victim const & victim) const;
	Sorcerer & operator = ( Sorcerer const & rhs );
};

std::ostream & operator << ( std::ostream & o, Sorcerer const & rhs );

#endif
