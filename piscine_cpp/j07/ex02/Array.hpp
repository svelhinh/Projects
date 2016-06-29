/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 12:15:52 by svelhinh          #+#    #+#             */
/*   Updated: 2016/06/28 12:17:36 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>

template<typename T>
class Array
{
	T		*_tab;
	int		_len;
public:
	Array()
	{
		_tab = new T[0];
		_len = 0;
	}

	Array(unsigned int n)
	{
		_tab = new T[n];
		_len = n;
	}

	Array(Array const &rhs)
	{
		_tab = new T[rhs._len];
		for(int i = 0; i < rhs._len; i++)
			_tab[i] = rhs._tab[i];
		_len = rhs._len;
	}

	Array	&operator=(Array const &rhs)
	{
		_tab = new T[rhs._len];

		for(int i = 0; i < rhs._len; i++)
			_tab[i] = rhs._tab[i];
		_len = rhs._len;
		return (*this);
	}

	T		&operator[](int i)
	{
		if (i >= _len)
			throw std::exception();
		else
			return _tab[i];
	}

	int	size()
	{
		return (_len);
	}
};

#endif
