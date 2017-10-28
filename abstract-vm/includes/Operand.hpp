/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 12:23:35 by svelhinh          #+#    #+#             */
/*   Updated: 2017/05/30 18:02:38 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Operand_hpp
#define Operand_hpp

#include "IOperand.hpp"
#include "Init.hpp"
#include "Exception.hpp"
#include <sstream>
#include <iomanip>

template< typename T >
class Operand : public IOperand
{
public:
	Operand( void );
	Operand( std::string const & value, eOperandType type );
	Operand( Operand< T > const & src );
	virtual ~Operand( void );

	int getPrecision( void ) const; // Precision of the type of the instance
	eOperandType getType( void ) const; // Type of the instance
	IOperand const * operator+( IOperand const & rhs ) const; // Sum
	IOperand const * operator-( IOperand const & rhs ) const; // Difference
	IOperand const * operator*( IOperand const & rhs ) const; // Product
	IOperand const * operator/( IOperand const & rhs ) const; // Quotient
	IOperand const * operator%( IOperand const & rhs ) const; // Modulo
	std::string const & toString( void ) const; // String representation of the instance

	Operand & operator=( Operand const & rhs );

private:
	T				_value;
	eOperandType	_type;
	std::string		_sValue;
	Init			*_init;
};

template< typename T >
Operand<T>::Operand( void )
{
	return ;
}

#include <iostream>

template< typename T >
Operand<T>::Operand( std::string const & value, eOperandType type ) : _type(type), _sValue(value)
{
	std::stringstream	ss(value);
	
	ss >> _value;
	_init = new Init();
	return ;
}

template< typename T >
Operand<T>::Operand( Operand<T> const & src ) : _type(src.getType()), _sValue(src.toString())
{
	std::stringstream	ss(src.toString());
	
	ss >> _value;
	*this = src;
	return ;
}

template< typename T >
Operand<T>::~Operand( void )
{
	return ;
}

template< typename T >
int		Operand<T>::getPrecision( void ) const
{
	int pos = _sValue.find('.');
	if (pos == -1)
		return 0;

	std::string str;
	str = _sValue.substr(pos, _sValue.size() - 1);
	return (str.size() - 1);
}

template< typename T >
eOperandType	Operand<T>::getType( void ) const
{
	return _type;	
}

template< typename T >
IOperand const * Operand<T>::operator+( IOperand const & rhs ) const
{
	std::stringstream	ss1(toString()), ss2(rhs.toString()), ss;
	long double			res, val1, val2;

	ss1 >> val1;
	ss2 >> val2;
	res = val1 + val2;
	if (getType() == Float || getType() == Double || rhs.getType() == Float || rhs.getType() == Double)
	{
		int	prec = getPrecision();
		if (rhs.getPrecision() > prec)
			prec = rhs.getPrecision();
		ss << std::fixed << std::setprecision(prec) << res;
	}
	else
		ss << res;
	if (getType() >= rhs.getType())
		return _init->createOperand(getType(), ss.str());
	return _init->createOperand(rhs.getType(), ss.str());
}

template< typename T >
IOperand const * Operand<T>::operator-( IOperand const & rhs ) const
{
	std::stringstream	ss1(toString()), ss2(rhs.toString()), ss;
	long double			res, val1, val2;

	ss1 >> val1;
	ss2 >> val2;
	res = val1 - val2;
	if (getType() == Float || getType() == Double || rhs.getType() == Float || rhs.getType() == Double)
	{
		int	prec = getPrecision();
		if (rhs.getPrecision() > prec)
			prec = rhs.getPrecision();
		ss << std::fixed << std::setprecision(prec) << res;
	}
	else
		ss << res;
	if (getType() >= rhs.getType())
		return _init->createOperand(getType(), ss.str());
	return _init->createOperand(rhs.getType(), ss.str());
}

template< typename T >
IOperand const * Operand<T>::operator*( IOperand const & rhs ) const
{
	std::stringstream	ss1(toString()), ss2(rhs.toString()), ss;
	long double			res, val1, val2;

	ss1 >> val1;
	ss2 >> val2;
	res = val1 * val2;
	if (getType() == Float || getType() == Double || rhs.getType() == Float || rhs.getType() == Double)
	{
		int	prec = getPrecision();
		if (rhs.getPrecision() > prec)
			prec = rhs.getPrecision();
		ss << std::fixed << std::setprecision(prec) << res;
	}
	else
		ss << res;
	if (getType() >= rhs.getType())
		return _init->createOperand(getType(), ss.str());
	return _init->createOperand(rhs.getType(), ss.str());
}

template< typename T >
IOperand const * Operand<T>::operator/( IOperand const & rhs ) const
{
	std::stringstream	ss1(toString()), ss2(rhs.toString()), ss;
	long double			res, val1, val2;

	ss1 >> val1;
	ss2 >> val2;
	if (!val2)
	{
		std::ostringstream	oss;

		oss << val1 << " / " << val2;
		std::string	str = oss.str();
		throw Exception::Exception("Division by 0", -1, &str);
	}
	res = val1 / val2;
	if (getType() == Float || getType() == Double || rhs.getType() == Float || rhs.getType() == Double)
	{
		int	prec = getPrecision();
		if (rhs.getPrecision() > prec)
			prec = rhs.getPrecision();
		ss << std::fixed << std::setprecision(prec) << res;
	}
	else
		ss << res;
	if (getType() >= rhs.getType())
		return _init->createOperand(getType(), ss.str());
	return _init->createOperand(rhs.getType(), ss.str());
}

template< typename T >
IOperand const * Operand<T>::operator%( IOperand const & rhs ) const
{
	std::stringstream	ss1(toString()), ss2(rhs.toString()), ss;
	long int			res, val1, val2;

	ss1 >> val1;
	ss2 >> val2;
	if (getType() == Float || getType() == Double || rhs.getType() == Float || rhs.getType() == Double)
	{
		std::ostringstream	oss;

		oss << toString() << " / " << rhs.toString();
		std::string	str = oss.str();
		throw Exception::Exception("Modulo between one float/double and/or a float/double", -1, &str);
	}
	if (!val2)
	{
		std::ostringstream	oss;

		oss << toString() << " / " << rhs.toString();
		std::string	str = oss.str();
		throw Exception::Exception("Modulo by 0", -1, &str);
	}
	res = val1 % val2;
	ss << res;
	if (getType() >= rhs.getType())
		return _init->createOperand(getType(), ss.str());
	return _init->createOperand(rhs.getType(), ss.str());
}

template< typename T >
std::string const & Operand<T>::toString( void ) const
{
	return _sValue;
}

template< typename T >
Operand<T> & Operand<T>::operator=( Operand const & rhs )
{
	std::stringstream	ss(rhs.toString());
	
	ss >> _value;
	_type = rhs.getType();
	_sValue = rhs.toString();

	return this;
}

#endif
