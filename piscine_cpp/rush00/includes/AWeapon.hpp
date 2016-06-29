/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 14:11:36 by svelhinh          #+#    #+#             */
/*   Updated: 2016/06/22 17:59:00 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWEAPON_HPP
# define AWEAPON_HPP
# include <iostream>
# include <ncurses.h>

class Ship;

class AWeapon
{
private:
	const std::string	_name;
	int					_damage;
	char const			_missile;
	int					_x;
	int					_y;
	int					_shoot;

public:
	AWeapon( std::string const & name, int damage, char const missile );
	AWeapon( AWeapon const & src );
	virtual ~AWeapon( void );

	std::string virtual	getName( void ) const;
	int					getDamage( void ) const;
	char				getMissile( void ) const;
	int					getX( void ) const;
	void				setX( int x );
	int					getY( void ) const;
	void				setY( int y );
	int					getShoot( void ) const;
	void				setShoot( int shoot );
	void virtual		shoot( Ship *ship ) = 0;

	AWeapon & operator = ( AWeapon const & rhs );
};

#endif
