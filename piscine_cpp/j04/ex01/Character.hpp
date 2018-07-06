/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 17:47:50 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/07 19:54:37 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include <iostream>
# include <cmath>
# include "AWeapon.hpp"
# include "Enemy.hpp"

class Character
{
private:
	Character();
	std::string const	_name;
	int					_ap;
	AWeapon				*_weapon;
public:
	Character( std::string const & name );
	Character( Character const & src );
	virtual ~Character( void );

	void		recoverAP( void );
	void		equip( AWeapon * );
	void		attack( Enemy * );

	std::string virtual getName( void ) const;
	int					getAP( void ) const;
	void				setAP( int ap );
	AWeapon				*getWeapon( void ) const;

	Character & operator = ( Character const & rhs );
};

std::ostream & operator << ( std::ostream & o, Character const & rhs );

#endif
