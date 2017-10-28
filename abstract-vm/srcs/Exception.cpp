#include "Exception.hpp"
#include <iostream>
#include <sstream>

Exception::Exception() : _msg("Error"), _line(-1), _instr(NULL)
{
	finalMessage();
	return;
}

Exception::Exception(const char * msg, int line, std::string *instr) : _msg(msg), _line(line), _instr(instr)
{
	finalMessage();
	return;
}

Exception::Exception(Exception const &src)
{
	*this = src;
}

Exception::~Exception() throw()
{
	return;
}

void	Exception::finalMessage() throw()
{
	std::ostringstream oss;

	if (_line != -1 && _instr)
		oss << "\033[34m" << "Line " << _line << " : \033[31m" << _msg << " : " << "\033[36m" << *_instr;
	else if (_line != -1)
		oss << "\033[34m" << "Line " << _line << " : \033[31m" << _msg;
	else if (_instr)
		oss << "\033[31m" << _msg << " : " << "\033[36m" << *_instr;
	else
		oss << "\033[31m" << _msg;
	oss << "\033[0m";
	_msgFinal = oss.str();
}

const char*		Exception::what() const throw()
{
	return _msgFinal.c_str();
}


const char	*Exception::getMsg() const
{
	return _msg;
}

int			Exception::getLine() const
{
	return _line;
}

std::string	*Exception::getInstr() const
{
	return _instr;
}

Exception	&Exception::operator=(Exception const &rhs)
{
	_msg = rhs.getMsg();
	_line = rhs.getLine();
	_instr = rhs.getInstr();
	return (*this);
}