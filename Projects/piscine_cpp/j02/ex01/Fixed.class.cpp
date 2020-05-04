/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 14:15:08 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/05 18:57:09 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.class.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void): fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed( Fixed const & src )
{
	std::cout << "Copy constructor called" << std::endl;

	*this = src;

	return;
}

Fixed::Fixed(int const nb)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixedPointValue = nb * (1 << Fixed::nbFracBits);					// nb * 256
	return;
}

Fixed::Fixed(float const nb)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixedPointValue = std::roundf(nb * (1 << Fixed::nbFracBits));		// nb * 256
	return;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;

	return;
}

int		Fixed::getRawBits( void ) const
{
	return this->fixedPointValue;
}

void	Fixed::setRawBits( int const raw )
{
	this->fixedPointValue = raw;
}

float	Fixed::toFloat( void ) const
{
	return this->fixedPointValue / (float)(1 << Fixed::nbFracBits);		// fixed / 256
}

int		Fixed::toInt( void ) const
{
	return this->fixedPointValue / (1 << Fixed::nbFracBits);			// fixed / 256
}

Fixed &	Fixed::operator=( Fixed const & rhs )
{
	std::cout << "Assignation operator called" << std::endl;

	this->setRawBits(rhs.getRawBits());
	return *this;
}

std::ostream &		operator<<( std::ostream & o, Fixed const & i)
{
	o << i.toFloat();

	return o;
}
