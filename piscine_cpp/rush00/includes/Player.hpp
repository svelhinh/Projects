/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 13:24:59 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/09 19:03:52 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Player_hpp
#define Player_hpp

#include "ACharacter.hpp"
#include <string>

class Player : public ACharacter
{
public:
	Player(void);
	Player(int, int, int, int, int color);
    Player(Player const & src);
    virtual ~Player(void);

	int			getLifes(void) const;

	Player &	operator=( Player const & rhs );

	virtual void	shoot(void);
	virtual void	takeDamage(int);
	virtual void	update(void);
	void	move(int x, int y);

private:
	int	_lifes;
};


#endif /* Player_hpp */
