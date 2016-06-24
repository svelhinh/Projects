/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 12:09:57 by svelhinh          #+#    #+#             */
/*   Updated: 2016/06/23 13:53:27 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
# define GAME_HPP
# include "Ship.hpp"
# include "Enemy.hpp"

class Game
{
private:
	Ship 				*_ship;
	Enemy 				*_enemy;
	int 				_maxx;
	int 				_maxy;
public:
    Game( void );
	Game( Game const & src );
	virtual ~Game( void );

	Ship		*getShip(void) const;
	Enemy		*getEnemy(void) const;
	int			getMaxX(void) const;
	int			getMaxY(void) const;
	void		setMaxX(int maxx);
	void		setMaxY(int maxy);

	Game & operator = ( Game const & rhs );
};


#endif
