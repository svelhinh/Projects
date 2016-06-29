/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 16:31:31 by svelhinh          #+#    #+#             */
/*   Updated: 2016/06/20 18:21:11 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POWERFIST_HPP
# define POWERFIST_HPP
# include <iostream>
# include <cmath>
# include "AWeapon.hpp"

class PowerFist : public AWeapon
{
public:
	PowerFist( void );
	PowerFist( PowerFist const & src );
	virtual ~PowerFist( void );

	void	attack( void ) const;

	PowerFist & operator = ( PowerFist const & rhs );
};

#endif
