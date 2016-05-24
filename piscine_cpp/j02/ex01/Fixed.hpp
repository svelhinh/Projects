#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed
{
private:
	int			_fix;
	const int	_frac;
public:
	Fixed( void );
	Fixed( int const nb );
	Fixed( float const nb );
	Fixed( Fixed const & src );
	~Fixed( void );
	float toFloat( void ) const;
	int toInt( void ) const;
	int getRawBits( void ) const;
	void setRawBits( int const raw );

	Fixed & operator = ( Fixed const & rhs );
};

std::ostream & operator << ( std::ostream & o, Fixed const & rhs );

#endif
