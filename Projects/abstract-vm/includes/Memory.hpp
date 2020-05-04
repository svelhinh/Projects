/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Memory.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 15:28:24 by svelhinh          #+#    #+#             */
/*   Updated: 2017/05/23 15:32:20 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Memory_hpp
#define Memory_hpp

#include "IOperand.hpp"
#include <list>

class Memory
{
public:
	Memory( void );
	Memory( Memory const & src );
	virtual ~Memory( void );

	std::list<IOperand const *>	getStack() const;

	void	memPushFront(IOperand const *);
	void	memPopFront();

	Memory & operator=( Memory const & rhs );
private:
	std::list<IOperand const *>	_stack;
};

#endif
