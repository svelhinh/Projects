#include "Fixed.hpp"

Fixed::Fixed(void): _fix(0), _frac(8)
{
	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed(int const nb): _frac(8)
{
	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(nb * pow(2, this->_frac));
	return;
}

Fixed::Fixed(float const nb): _frac(8)
{
	std::cout << "Float constructor called" << std::endl;
	this->setRawBits(roundf(nb * pow(2, this->_frac)));
	return;
}

float Fixed::toFloat( void ) const
{
	return this->getRawBits()/pow(2,this->_frac);
}

int Fixed::toInt( void ) const
{
	return this->getRawBits()/pow(2,this->_frac);
}

Fixed::Fixed(Fixed const & src): _frac(8)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

int Fixed::getRawBits( void ) const
{
	return this->_fix;
}

void Fixed::setRawBits( int const raw )
{
	this->_fix = raw;
}

Fixed & Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_fix = rhs.getRawBits();
	return *this;
}

std::ostream & operator << ( std::ostream & o, Fixed const & rhs )
{
	o << rhs.toFloat();
	return o;
}
