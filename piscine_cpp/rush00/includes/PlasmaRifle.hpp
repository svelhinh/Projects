/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 16:19:15 by svelhinh          #+#    #+#             */
/*   Updated: 2016/06/22 18:08:06 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP
# include "AWeapon.hpp"
# include "Ship.hpp"
# include "ft_retro.hpp"

class Ship;
class AWeapon;

class PlasmaRifle : public AWeapon
{
public:
	PlasmaRifle( void );
	PlasmaRifle( PlasmaRifle const & src );
	virtual ~PlasmaRifle( void );

	void	shoot( Ship *ship );

	PlasmaRifle & operator = ( PlasmaRifle const & rhs );
};

#endif
