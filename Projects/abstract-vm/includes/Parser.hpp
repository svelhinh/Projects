/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 15:45:13 by svelhinh          #+#    #+#             */
/*   Updated: 2017/05/30 19:58:52 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Parser_hpp
#define Parser_hpp

#include "Memory.hpp"
#include "Init.hpp"
#include "Exception.hpp"
#include <string>
#include <fstream>

class Parser
{
public:
	Parser( void );
	Parser( int, char **);
	Parser( Parser const & );
	virtual ~Parser( void );

	Memory	getMemory( void ) const;

	Parser & operator=( Parser const & );

private:
	Init		_init;
	Memory		_mem;
	std::string	_line;
	int			_nbLine = 0;

	void	parsing(std::string filename = "");
	void	parseStr(std::string);
	void	parseStrInput(std::string);

	void	push(std::string);
	void	pop();
	void	assert(std::string) const;
	void	add();
	void	sub();
	void	mul();
	void	div();
	void	mod();
	void	print();
	void	dump() const;
};

#endif
