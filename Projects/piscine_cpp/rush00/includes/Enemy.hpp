/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 13:24:59 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/09 19:03:32 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Enemy_hpp
#define Enemy_hpp

#include "ACharacter.hpp"
#include <string>

enum e_speedLevels
{
	e_speedLvl0 = 3,
	e_speedLvl1 = 2,
	e_speedLvl2 = 1,
	e_speedLvl3 = 0
};

class Enemy : public ACharacter
{
public:
	Enemy(void);
	Enemy(int pv, int x, int y, int givenScore, int color);
    Enemy(Enemy const & src);
    virtual ~Enemy(void);

	int			getGivenScore(void) const;
	void		setSpeedLevel(int score);

	Enemy &	operator=( Enemy const & rhs );

	virtual void	shoot(void);
	virtual void	takeDamage(int);
	virtual void	update(void);

private:
	int _elapsedTicks;
	int	_givenScore;
	enum e_speedLevels	_speedLevel;
};


#endif /* Enemy_hpp */
