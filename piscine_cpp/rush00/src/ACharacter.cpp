/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ACharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 13:25:27 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/09 20:07:42 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ACharacter.hpp"
#include "UserInterface.hpp"
#include "Game.hpp"

ACharacter::ACharacter(void)
	: AHitBox(0, 0, 0, 0), _pv(10), _shape(".")
{
}

ACharacter::ACharacter(int pv, int x, int y, int w, int h, const std::string shape,
	int color)
	: AHitBox(x, y, w, h), _pv(pv), _shape(shape), _color(color)
{
}

ACharacter::ACharacter(ACharacter const & src)
{
	*this = src;
	return;
}

ACharacter::~ACharacter(void)
{
}

int ACharacter::getPv(void) const
{
	return _pv;
}

std::string const ACharacter::getShape(void) const
{
	return _shape;
}

void ACharacter::setPv(int pv_)
{
	_pv = pv_;
}

void	ACharacter::draw(void)
{
	int offx = 0;
	int offy = 0;

	for (int i = 0; _shape[i] != '\0'; i++) {
		if (_shape[i] == '\n') {
			offy++;
			offx = 0;
		}
		else {
			if (_y + offy > 0 && _y + offy < MAPH && _x + offx > 0 && _x + offx < MAPL)
				mvprintcColor(_y + offy, _x + offx, _shape[i], _color);
			offx++;
		}
	}


	// size_t pos = 0;
	// std::string splitShape;
	// std::string tmpShape = _shape;
	// while ((pos = tmpShape.find("\n")) != std::string::npos) {
	//     splitShape = tmpShape.substr(0, pos);
	// 	mvprintw(_y, _x, splitShape.c_str());
	//     tmpShape.erase(0, pos + 1);
	// }
}

void	ACharacter::move(int x, int y)
{
	_x = x + _x;
	_y = y + _y;
}

bool	ACharacter::isAlive(void) const
{
	return _pv > 0;
}

ACharacter &	ACharacter::operator=( ACharacter const & rhs )
{
	_pv = rhs.getPv();
	return *this;
}
