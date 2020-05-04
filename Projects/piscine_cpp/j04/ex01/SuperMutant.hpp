/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 17:32:45 by svelhinh          #+#    #+#             */
/*   Updated: 2016/06/20 17:43:15 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERMUTANT_HPP
# define SUPERMUTANT_HPP
# include <iostream>
# include <cmath>
# include "Enemy.hpp"

class SuperMutant : public Enemy
{
public:
	SuperMutant( void );
	SuperMutant( SuperMutant const & src );
	virtual ~SuperMutant( void );

	virtual void		takeDamage( int );

	SuperMutant & operator = ( SuperMutant const & rhs );
};

#endif
