/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 14:15:03 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/05 15:10:12 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

class Fixed
{
public:
    Fixed( void );
    Fixed( Fixed const & src );
	~Fixed( void );

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

    Fixed &	operator=( Fixed const & rhs );

private:
	int					fixedPointValue;
	static const int	nbFracBits = 8;
};


#endif
