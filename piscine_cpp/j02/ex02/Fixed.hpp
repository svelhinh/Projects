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
	bool operator > ( Fixed const & rhs ) const;
	bool operator < ( Fixed const & rhs ) const;
	bool operator >= ( Fixed const & rhs ) const;
	bool operator <= ( Fixed const & rhs ) const;
	bool operator == ( Fixed const & rhs ) const;
	bool operator != ( Fixed const & rhs ) const;
	Fixed operator + ( Fixed const & rhs ) const;
	Fixed operator - ( Fixed const & rhs ) const;
	Fixed operator * ( Fixed const & rhs ) const;
	Fixed operator / ( Fixed const & rhs ) const;
	Fixed & operator ++ ( void );
	Fixed & operator -- ( void );
	Fixed operator ++ ( int );
	Fixed operator -- ( int );
	static Fixed & min( Fixed &fix1, Fixed &fix2 );
	static Fixed & max( Fixed &fix1, Fixed &fix2 );
	static Fixed const &min(Fixed const &fix1, const Fixed &fix2);
	static Fixed const &max(Fixed const &fix1, const Fixed &fix2);
};

std::ostream & operator << ( std::ostream & o, Fixed const & rhs );

#endif
