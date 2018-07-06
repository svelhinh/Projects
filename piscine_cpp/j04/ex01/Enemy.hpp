/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 17:15:20 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/07 19:59:00 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP
# include <iostream>
# include <cmath>

class Enemy
{
private:
	Enemy();
	int					_hp;
	const std::string	_type;

public:
	Enemy(int hp, std::string const & type);
	Enemy( Enemy const & src );
	virtual ~Enemy( void );

	std::string virtual	getType( void ) const;
	int					getHP( void ) const;
	void				setHP( int );

	virtual void		takeDamage( int );

	Enemy & operator = ( Enemy const & rhs );
};

#endif
