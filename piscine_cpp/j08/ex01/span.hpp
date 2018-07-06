/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 12:05:03 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/13 14:53:38 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef span_hpp
#define span_hpp

#include <vector>

class Span
{
public:
	Span( unsigned int N );
	Span( Span const & src );
	virtual ~Span( void );

	void	addNumber( std::vector<int> value );
	void	addNumber( int value );
	int		shortestSpan(void);
	int		longestSpan(void);

	Span & operator=( Span const & rhs );

	std::vector<int>	_intList;
	unsigned int	_N;

private:
	Span( void );
};

#endif
