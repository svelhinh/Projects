/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Memory.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 15:28:30 by svelhinh          #+#    #+#             */
/*   Updated: 2017/05/23 15:28:30 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Memory.hpp"

Memory::Memory( void )
{
	return;
}

Memory::Memory( Memory const & src )
{
	*this = src;
	return;
}

Memory::~Memory( void )
{
	return;
}

std::list<IOperand const *>	Memory::getStack() const
{
	return _stack;
}

void	Memory::memPushFront(IOperand const * op)
{
	_stack.push_front(op);
}

void	Memory::memPopFront()
{
	_stack.pop_front();
}

Memory & Memory::operator=( Memory const & rhs )
{
	_stack = rhs.getStack();
	return *this;
}
