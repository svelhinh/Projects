/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Init.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 13:59:11 by svelhinh          #+#    #+#             */
/*   Updated: 2017/05/30 12:55:09 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Init_hpp
#define Init_hpp

#include "IOperand.hpp"

class Init
{
private:
	IOperand const * createInt8( std::string const & value ) const;
	IOperand const * createInt16( std::string const & value ) const;
	IOperand const * createInt32( std::string const & value ) const;
	IOperand const * createFloat( std::string const & value ) const;
	IOperand const * createDouble( std::string const & value ) const;

	IOperand const *(Init::*create[5])(std::string const &) const;

public:
	Init( void );
	Init( Init const & src );
	virtual ~Init( void );

	template <typename T>
	void	checkFlow( std::string const & value ) const;
	IOperand const * createOperand( eOperandType type, std::string const & value ) const;

	Init & operator=( Init const & rhs );
};

#endif
