/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 14:28:16 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/14 15:02:25 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef mutantstack_hpp
#define mutantstack_hpp

#include <stack>
#include <iterator>

template< typename T >
class MutantStack : public std::stack<T>
{
public:
	MutantStack( void );
	MutantStack( MutantStack< T > const & src );
	virtual ~MutantStack( void );


    class iterator
    {
    public:
        T* _num;
        iterator( void );
        iterator( iterator const & src );
        iterator(long num);
        virtual ~iterator( void );

        iterator& operator++( void );
        iterator operator++( int );
        iterator& operator--( void );
        iterator operator--( int );
        bool operator==(iterator rhs) const;
        bool operator!=(iterator rhs) const;
        T operator*() const;
    };
    iterator begin( void );
    iterator end( void );

	MutantStack & operator=( MutantStack const & rhs );
};

#endif
