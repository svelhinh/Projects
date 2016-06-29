/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 13:32:08 by svelhinh          #+#    #+#             */
/*   Updated: 2016/06/28 13:55:41 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

Span::Span(unsigned int n): _n(n), _tab()
{
	return;
}

Span::Span(Span const &rhs)
{
	*this = rhs;
	return;
}

Span::~Span()
{
	return;
}

Span & Span::operator=(Span const &rhs)
{
	(void)rhs;
	return *this;
}

void	Span::addNumber(int nb)
{
	if (_tab.size() != _n)
		_tab.push_back(nb);
	else
		throw std::exception();
}

int		Span::shortestSpan()
{
	if (_tab.size() <= 1)
		throw std::exception();
	return *std::min_element(_tab.begin(), _tab.end());
}

int		Span::longestSpan()
{
	if (_tab.size() <= 1)
		throw std::exception();
	return *std::max_element(_tab.begin(), _tab.end());
}
