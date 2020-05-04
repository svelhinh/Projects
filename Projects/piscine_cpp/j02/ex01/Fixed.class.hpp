/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 14:15:03 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/05 16:02:12 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

# include <iostream>

class Fixed
{
public:
    Fixed( void );
    Fixed( Fixed const & src );
	Fixed(int const nb);
	Fixed(float const nb);
	~Fixed( void );

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

	int		toInt( void ) const;
	float	toFloat( void ) const;

    Fixed &	operator=( Fixed const & rhs );

private:
	int					fixedPointValue;
	static const int	nbFracBits = 8;
};

std::ostream &		operator<<( std::ostream & o, Fixed const & i);

#endif
