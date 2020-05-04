/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 13:25:27 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/09 19:03:43 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"
#include "Game.hpp"

Player::Player(void)
	: ACharacter(1, 1, 1, 2, 1, "=>", C_WHITEBLACK), _lifes(3)
{
}

Player::Player(int pv, int x, int y, int lifes_, int color)
	: ACharacter(pv, x, y, 2, 1, "=>", color), _lifes(lifes_)
{
}

Player::Player(Player const & src)
{
	*this = src;
	return;
}

Player::~Player(void)
{
}

int	Player::getLifes(void) const
{
	return _lifes;
}

void	Player::shoot(void)
{
	// TODO
}

void	Player::takeDamage(int amount)
{
	(void)amount;
}

void	Player::update(void)
{
}

void	Player::move(int x, int y)
{
	int	mvX = _x + x;
	int	mvY = _y + y;

	if (mvX <= 0 || mvX > MAPL - getWidth() || mvY <= 0 || mvY >= MAPH - getHeight() + 1)
		return;
	_x = x + _x;
	_y = y + _y;
}

Player &	Player::operator=( Player const & rhs )
{
	_pv = rhs.getPv();
	return *this;
}
