/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Init.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 14:53:04 by svelhinh          #+#    #+#             */
/*   Updated: 2017/06/07 15:02:10 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Init.hpp"
#include "Operand.hpp"
#include "Exception.hpp"
#include <limits>

Init::Init( void )
{
	create[0] = &Init::createInt8;
	create[1] = &Init::createInt16;
	create[2] = &Init::createInt32;
	create[3] = &Init::createFloat;
	create[4] = &Init::createDouble;
	return;
}

Init::Init( Init const & src )
{
	*this = src;
	return;
}

Init::~Init( void )
{
	return;
}

Init & Init::operator=( Init const & rhs )
{
	(void)rhs;
	create[0] = &Init::createInt8;
	create[1] = &Init::createInt16;
	create[2] = &Init::createInt32;
	create[3] = &Init::createFloat;
	create[4] = &Init::createDouble;
	return *this;
}

template <typename T>
void	Init::checkFlow( std::string const & value ) const
{
	std::string realValue = value;
	std::stringstream	ss(realValue);
	long double		nValue;
	std::ostringstream	oss;

	int pos = value.find('.');

	ss >> nValue;
	if (nValue < std::numeric_limits<T>::lowest())
	{
		oss << "Underflow on value ( min : " << std::to_string(std::numeric_limits<T>::lowest()) << " ) : ";
		throw Exception::Exception(oss.str().c_str(), -1, &realValue);
	}
	else if (pos != -1 && value.size() - pos - 1 > std::numeric_limits<T>::max_digits10)
	{
		oss << "Too much precision for this type ( max digits : " << std::numeric_limits<T>::max_digits10 << " )";
		throw Exception::Exception(oss.str().c_str(), -1, &realValue);
	}
	if (nValue > std::numeric_limits<T>::max())
	{
		oss << "Overflow on value ( max : " << std::to_string(std::numeric_limits<T>::lowest()) << " ) : ";
		throw Exception::Exception(oss.str().c_str(), -1, &realValue);
	}
}

IOperand const * Init::createInt8( std::string const & value ) const
{
	checkFlow<char>(value);
	return (new Operand<char>(value, Int8));
}

IOperand const * Init::createInt16( std::string const & value ) const
{
	checkFlow<short int>(value);
	return (new Operand<short int>(value, Int16));
}

IOperand const * Init::createInt32( std::string const & value ) const
{
	checkFlow<int>(value);
	return (new Operand<int>(value, Int32));
}

IOperand const * Init::createFloat( std::string const & value ) const
{
	checkFlow<float>(value);
	return (new Operand<float>(value, Float));
}

IOperand const * Init::createDouble( std::string const & value ) const
{
	checkFlow<double>(value);
	return (new Operand<double>(value, Double));
}

IOperand const * Init::createOperand( eOperandType type, std::string const & value ) const
{
	if (type >= Int8 && type <= Double)
		return (this->*create[type])(value);
	return (NULL);
}
