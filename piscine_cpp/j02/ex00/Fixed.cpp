#include "Fixed.hpp"

Fixed::Fixed(void): _fix(0), _frac(8)
{
	std::cout << "Default constructor called" << std::endl;
	return;
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
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fix;
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "set" << std::endl;
	this->_fix = raw;
}

Fixed & Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_fix = rhs.getRawBits();
	return *this;
}
