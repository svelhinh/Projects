/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 14:15:08 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/05 19:42:45 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.class.hpp"
#include <iostream>
#include <cmath>


// -----------------------------------------------------------------------------
// CONSTRUCTORS/DESTRUCTORS
// -----------------------------------------------------------------------------

Fixed::Fixed(void): fixedPointValue(0)
{
	return;
}

Fixed::Fixed( Fixed const & src )
{
	*this = src;

	return;
}

Fixed::Fixed(int const nb)
{
	this->fixedPointValue = nb * (1 << Fixed::nbFracBits);
	return;
}

Fixed::Fixed(float const nb)
{
	this->fixedPointValue = std::roundf(nb * (1 << Fixed::nbFracBits));
	return;
}

Fixed::~Fixed(void)
{

	return;
}


// -----------------------------------------------------------------------------
// ACCESSORS
// -----------------------------------------------------------------------------

int		Fixed::getRawBits( void ) const
{
	return this->fixedPointValue;
}

void	Fixed::setRawBits( int const raw )
{
	this->fixedPointValue = raw;
}


// -----------------------------------------------------------------------------
// MEMBER FUNCTIONS
// -----------------------------------------------------------------------------

float	Fixed::toFloat( void ) const
{
	return this->fixedPointValue / (float)(1 << Fixed::nbFracBits);
}

int		Fixed::toInt( void ) const
{
	return this->fixedPointValue / (1 << Fixed::nbFracBits);
}


// -----------------------------------------------------------------------------
// OVERLOAD OPERATORS
// -----------------------------------------------------------------------------

Fixed &	Fixed::operator=( Fixed const & rhs )
{
	this->setRawBits(rhs.getRawBits());
	return *this;
}

bool	Fixed::operator>( Fixed const & rhs ) const
{
	return (this->toFloat() > rhs.toFloat());
}

bool	Fixed::operator<( Fixed const & rhs ) const
{
	return (this->toFloat() < rhs.toFloat());
}

bool	Fixed::operator<=( Fixed const & rhs ) const
{
	return (this->toFloat() <= rhs.toFloat());
}

bool	Fixed::operator>=( Fixed const & rhs ) const
{
	return (this->toFloat() >= rhs.toFloat());
}

bool	Fixed::operator==( Fixed const & rhs ) const
{
	return (this->toFloat() == rhs.toFloat());
}

bool	Fixed::operator!=( Fixed const & rhs ) const
{
	return (this->toFloat() != rhs.toFloat());
}

Fixed	Fixed::operator+( Fixed const & rhs ) const
{
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed	Fixed::operator-( Fixed const & rhs ) const
{
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed	Fixed::operator*( Fixed const & rhs ) const
{
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/( Fixed const & rhs ) const
{
	return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed &	Fixed::operator++()
{
	this->fixedPointValue++;
	return *this;
}

Fixed	Fixed::operator++( int )
{
	Fixed tmp(*this);

	++(*this);
	return tmp;
}

Fixed &	Fixed::operator--()
{
	this->fixedPointValue--;
	return *this;
}

Fixed	Fixed::operator--( int )
{
	Fixed tmp(*this);

	--(*this);
	return tmp;
}

Fixed & Fixed::min( Fixed &fix1, Fixed &fix2 )
{
	return fix1 < fix2 ? fix1 : fix2;
}

Fixed const &Fixed::min(Fixed const &fix1, const Fixed &fix2)
{
	return fix1 < fix2 ? fix1 : fix2;
}

Fixed & Fixed::max( Fixed &fix1, Fixed &fix2 )
{
	return fix1 < fix2 ? fix2 : fix1;
}

Fixed const &Fixed::max(Fixed const &fix1, const Fixed &fix2)
{
	return fix1 < fix2 ? fix2 : fix1;
}

std::ostream &		operator<<( std::ostream & o, Fixed const & i)
{
	o << i.toFloat();

	return o;
}
