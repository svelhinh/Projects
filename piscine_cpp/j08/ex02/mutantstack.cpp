/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 14:24:32 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/14 15:04:31 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"

template< typename T >
MutantStack<T>::MutantStack( void )
{
	return;
}

template< typename T >
MutantStack<T>::MutantStack( MutantStack<T> const & src )
{
	*this = src;
	return;
}

template< typename T >
MutantStack<T>::~MutantStack( void )
{
	return;
}

template< typename T >
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	T*	tmp = &(this->top());
	unsigned long i = 0;
	while (i < this->size() - 1)
	{
		tmp--;
		i++;
	}
	iterator it;
	it._num = tmp;
	return it;
}

template< typename T >
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	T*    tmp = &(this->top()) + 1;
	iterator it;
	it._num = tmp;
	return it;
}







template<typename T>
MutantStack<T>::iterator::iterator( void ): _num(0)
{
	return;
}

template<typename T>
MutantStack<T>::iterator::iterator(long num): _num(num)
{
	return;
}

template<typename T>
MutantStack<T>::iterator::iterator( typename MutantStack<T>::iterator const & src )
{
	*this = src;
	return;
}

template<typename T>
MutantStack<T>::iterator::~iterator( void )
{
	return;
}

template<typename T>
typename MutantStack<T>::iterator& MutantStack<T>::iterator::operator++( void )
{
	_num++;
	return *this;
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::iterator::operator++( int )
{
	iterator retval = *this;
	++(*this);
	return retval;
}

template<typename T>
typename MutantStack<T>::iterator& MutantStack<T>::iterator::operator--( void )
{
	_num--;
	return *this;
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::iterator::operator--( int )
{
	iterator retval = *this;
	--(*this);
	return retval;
}

template<typename T>
bool MutantStack<T>::iterator::operator==(MutantStack<T>::iterator rhs) const
{
	return _num == rhs._num;
}

template<typename T>
bool MutantStack<T>::iterator::operator!=(MutantStack<T>::iterator rhs) const
{
	return !(*this == rhs);
}

template<typename T>
T MutantStack<T>::iterator::operator*( void ) const
{
	return *_num;
}
