/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ACharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 13:24:59 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/09 19:36:16 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Acharacter_hpp
#define Acharacter_hpp

#include <string>
#include <ncurses.h>
#include "AHitBox.hpp"

class ACharacter : public AHitBox
{
public:
    ACharacter(void);
	ACharacter(int pv, int y, int x, int w, int h, const std::string shape,
		int color);
    ACharacter(ACharacter const & src);
    virtual ~ACharacter(void);

	int					getPv(void) const;
	std::string const	getShape(void) const;

	void	setPv(int pv_);

	void	draw(void);
	void	move(int x, int y);

	bool	isAlive(void) const;

	ACharacter &	operator=( ACharacter const & rhs );

protected:
	int					_pv;
	std::string			_shape;

	int	_color;

	virtual void	shoot(void) = 0;
	virtual void	takeDamage(int) = 0;
	virtual void	update(void) = 0;
};


#endif /* Acharacter_hpp */
