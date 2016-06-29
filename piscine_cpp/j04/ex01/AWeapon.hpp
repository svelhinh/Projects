/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 15:47:22 by svelhinh          #+#    #+#             */
/*   Updated: 2016/06/20 16:28:32 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWEAPON_HPP
# define AWEAPON_HPP
# include <iostream>
# include <cmath>

class AWeapon
{
private:
	const std::string	_name;
	int					_apcost;
	int					_damage;

public:
	AWeapon(std::string const & name, int apcost, int damage);
	AWeapon( AWeapon const & src );
	virtual ~AWeapon( void );

	std::string virtual	getName( void ) const;
	int					getAPCost( void ) const;
	int					getDamage( void ) const;
	virtual void		attack( void )	const = 0;

	AWeapon & operator = ( AWeapon const & rhs );
};

#endif
