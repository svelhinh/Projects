/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 12:05:01 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/13 15:49:40 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <numeric>

Span::Span( void )
{
	return;
}

Span::Span( unsigned int N ): _N(N)
{
	return;
}

Span::Span( Span const & src )
{
	*this = src;
	return;
}

Span::~Span( void )
{
	return;
}

void	Span::addNumber( std::vector<int> range )
{
	if (_intList.size() >= _N)
		throw std::exception();
	else
		_intList.insert(_intList.end(), range.begin(), range.end());
}

void	Span::addNumber( int value )
{
	if (_intList.size() >= _N)
		throw std::exception();
	else
		_intList.push_back(value);
}

int		Span::shortestSpan(void)
{
	if (_intList.size() < 2)
		throw std::exception();
	else
	{
		std::vector<int> 	cpy = _intList;

	    std::sort(cpy.begin(), cpy.end());
		std::adjacent_difference(cpy.begin(), cpy.end(), cpy.begin() - 1);
		cpy.pop_back();
	    return *std::min_element(cpy.begin(), cpy.end());
	}
}

int		Span::longestSpan(void)
{
	if (_intList.size() < 2)
		throw std::exception();
	else
	{
		std::vector<int>::iterator	min = std::min_element(_intList.begin(), _intList.end());
		std::vector<int>::iterator	max = std::max_element(_intList.begin(), _intList.end());

		return (_intList[std::distance(_intList.begin(), max)] - _intList[std::distance(_intList.begin(), min)]);
	}
}

Span & Span::operator=( Span const & rhs )
{
	_N = rhs._N;
	_intList = rhs._intList;
	return *this;
}
