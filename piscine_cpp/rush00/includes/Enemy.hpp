/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 11:27:02 by svelhinh          #+#    #+#             */
/*   Updated: 2016/06/23 11:38:20 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP
# include <iostream>
# include <ncurses.h>

class Enemy
{
private:
	std::string const 	_shape;
	int					_x;
	int					_y;
public:
    Enemy( int const maxx );
	Enemy( Enemy const & src );
	virtual ~Enemy( void );

	std::string	getShape(void) const;
	int			getX(void) const;
	int			getY(void) const;
	void		setX(int x);
	void		setY(int y);
	void		displayEnemy( void ) const;

	Enemy & operator = ( Enemy const & rhs );
};


#endif
