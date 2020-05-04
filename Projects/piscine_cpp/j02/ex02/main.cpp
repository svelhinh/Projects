#include "Fixed.hpp"
#include <iostream>

int main( void )
{
	Fixed a;
	// Fixed c = 70;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	// std::cout << a + c << std::endl;
	// std::cout << a - c << std::endl;
	// std::cout << a * c << std::endl;
	// std::cout << a / c << std::endl;

	// if (a > c)
	// 	std::cout << "true" << std::endl;
	// else
	// 	std::cout << "false" << std::endl;
	// if (a >= c)
	// 	std::cout << "true" << std::endl;
	// else
	// 	std::cout << "false" << std::endl;
	// if (a < c)
	// 	std::cout << "true" << std::endl;
	// else
	// 	std::cout << "false" << std::endl;
	// if (a <= c)
	// 	std::cout << "true" << std::endl;
	// else
	// 	std::cout << "false" << std::endl;
	// if (a == c)
	// 	std::cout << "true" << std::endl;
	// else
	// 	std::cout << "false" << std::endl;
	// if (a != c)
	// 	std::cout << "true" << std::endl;
	// else
	// 	std::cout << "false" << std::endl;

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	// std::cout << (Fixed::min(a, b) == a ? "a" : "b") << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}
