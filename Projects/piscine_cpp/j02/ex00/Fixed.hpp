#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
private:
	int			_fix;
	const int	_frac;
public:
	Fixed( void );
	Fixed( Fixed const & src );
	~Fixed( void );
	int getRawBits( void ) const;
	void setRawBits( int const raw );

	Fixed & operator = ( Fixed const & rhs );
};

#endif
