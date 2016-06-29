/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 15:27:59 by svelhinh          #+#    #+#             */
/*   Updated: 2016/06/20 17:21:21 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_HPP
# define VICTIM_HPP
# include <iostream>
# include <cmath>

class Victim
{
private:
	const std::string _name;
	Victim();

public:
	Victim( std::string name );
	Victim( Victim const & src );
	virtual ~Victim( void );

	std::string		getName( void ) const;
	virtual void	getPolymorphed( void ) const;

	Victim & operator = ( Victim const & );
};

std::ostream & operator << ( std::ostream & o, Victim const & rhs );

#endif
