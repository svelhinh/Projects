/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 13:32:17 by svelhinh          #+#    #+#             */
/*   Updated: 2016/06/28 13:51:44 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP
# include <vector>
# include <iostream>

class	Span
{
private:
	unsigned int		_n;
	std::vector<int>	_tab;
public:
	Span(unsigned int n);
	Span(Span const &rhs);
	virtual ~Span();

	void	addNumber(int nb);
	int		shortestSpan();
	int		longestSpan();

	Span & operator=(Span const &rhs);
};

#endif
