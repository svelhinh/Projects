#include "Fixed.hpp"

Fixed::Fixed(void): _fix(0), _frac(8)
{
	return;
}

Fixed::Fixed(int const nb): _frac(8)
{
	this->setRawBits(nb * pow(2, this->_frac));
	return;
}

Fixed::Fixed(float const nb): _frac(8)
{
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
	*this = src;
	return;
}

Fixed::~Fixed(void)
{
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
	this->_fix = rhs.getRawBits();
	return *this;
}

bool Fixed::operator>(Fixed const & rhs) const
{
	return (this->toFloat() > rhs.toFloat());
}

bool Fixed::operator<(Fixed const & rhs) const
{
	return (this->toFloat() < rhs.toFloat());
}

bool Fixed::operator>=(Fixed const & rhs) const
{
	return (this->toFloat() >= rhs.toFloat());
}

bool Fixed::operator<=(Fixed const & rhs) const
{
	return (this->toFloat() <= rhs.toFloat());
}

bool Fixed::operator==(Fixed const & rhs) const
{
	return (this->toFloat() == rhs.toFloat());
}

bool Fixed::operator!=(Fixed const & rhs) const
{
	return (this->toFloat() != rhs.toFloat());
}

Fixed Fixed::operator+(Fixed const & rhs) const
{
	return (this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(Fixed const & rhs) const
{
	return (this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(Fixed const & rhs) const
{
	return (this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(Fixed const & rhs) const
{
	return (this->toFloat() / rhs.toFloat());
}

Fixed & Fixed::operator++(void)
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed & Fixed::operator--(void)
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed copy(*this);
	++(*this);
	return (copy);
}

Fixed Fixed::operator--(int)
{
	Fixed copy(*this);
	--(*this);
	return (copy);
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

std::ostream & operator << ( std::ostream & o, Fixed const & rhs )
{
	o << rhs.toFloat();
	return o;
}
