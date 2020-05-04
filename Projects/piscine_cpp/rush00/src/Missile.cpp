/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Missile.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 13:25:27 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/09 20:41:24 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Missile.hpp"
#include "Game.hpp"

Missile::Missile(void)
	: AHitBox(1, 1, 1, 1), _shape("-")
{
}

Missile::Missile(int x, int y)
	: AHitBox(x, y, 1, 1), _shape("-")
{
}

Missile::Missile(Missile const & src)
{
	*this = src;
	return;
}

Missile::~Missile(void)
{
}

void Missile::update(void)
{
	move(1, 0);
}

void	Missile::draw(void)
{
	mvprintw(_y, _x, _shape.c_str());
}

void	Missile::move(int x, int y)
{
	_x = x + _x;
	_y = y + _y;
}

Missile &	Missile::operator=( Missile const & rhs )
{
	(void)rhs;
	return *this;
}
