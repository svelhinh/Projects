/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ship.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 14:11:36 by svelhinh          #+#    #+#             */
/*   Updated: 2016/06/22 17:59:05 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHIP_HPP
# define SHIP_HPP
# include "PlasmaRifle.hpp"
# include "AWeapon.hpp"

class Ship
{
private:
	AWeapon 			*_weapon;
	std::string const 	_shape;
	int					_x;
	int					_y;
public:
    Ship( int const maxx, int const maxy );
	Ship( Ship const & src );
	virtual ~Ship( void );

	AWeapon		*getWeapon(void) const;
	std::string	getShape(void) const;
	int			getX(void) const;
	int			getY(void) const;
	void		setX(int x);
	void		setY(int y);
	void		displayShip( void ) const;

	Ship & operator = ( Ship const & rhs );
};


#endif
