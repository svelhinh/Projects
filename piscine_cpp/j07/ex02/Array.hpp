/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 16:42:09 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/12 18:17:59 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Array_hpp
#define Array_hpp

#include <iostream>

template<typename T>
class Array
{
public:
	Array( void ): _size(0)
	{
		_array = new T[0];
		return;
	}
	Array( unsigned int n ): _size(n)
	{
		_array = new T[n];
		for (size_t i = 0; i < n; i++)
			_array[i] = T();
		return;
	}
	Array( Array<T> const & src )
	{
		*this = src;
		return;
	}
	virtual ~Array( void )
	{
		return;
	}

	Array<T> & operator=( Array<T> const & rhs )
	{
		_array = rhs._array;
		_size = rhs.size();
		return *this;
	}

	T & operator[]( size_t const rhs )
	{
		if (rhs >= 0 && rhs < _size)
			return _array[rhs];
		throw std::exception();
	}

	size_t	size() const
	{
		return _size;
	}

	T *_array;

private:
	size_t _size;
};

#endif
