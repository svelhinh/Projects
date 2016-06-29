/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 15:28:10 by svelhinh          #+#    #+#             */
/*   Updated: 2016/06/20 15:39:12 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_HPP
# define PEON_HPP
# include <iostream>
# include <cmath>
# include "Victim.hpp"

class Peon : public Victim
{
private:
	Peon();

public:
	Peon( std::string name );
	Peon( Peon const & src );
	virtual ~Peon( void );

	virtual void	getPolymorphed( void ) const;

	Peon & operator = ( Peon const & rhs );
};

#endif
