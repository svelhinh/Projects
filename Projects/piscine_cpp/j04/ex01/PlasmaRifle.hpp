/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 16:19:15 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/07 19:57:53 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP
# include <iostream>
# include <cmath>
# include "AWeapon.hpp"

class PlasmaRifle : public AWeapon
{
public:
	PlasmaRifle( void );
	PlasmaRifle( PlasmaRifle const & src );
	virtual ~PlasmaRifle( void );

	void	attack( void ) const;

	PlasmaRifle & operator = ( PlasmaRifle const & rhs );
};

#endif
