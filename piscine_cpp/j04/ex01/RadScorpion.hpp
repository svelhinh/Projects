/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 17:34:09 by svelhinh          #+#    #+#             */
/*   Updated: 2016/06/20 17:43:11 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RADSCORPION_HPP
# define RADSCORPION_HPP
# include <iostream>
# include <cmath>
# include "Enemy.hpp"

class RadScorpion : public Enemy
{
public:
	RadScorpion( void );
	RadScorpion( RadScorpion const & src );
	virtual ~RadScorpion( void );

	virtual void		takeDamage( int );

	RadScorpion & operator = ( RadScorpion const & rhs );
};

#endif
