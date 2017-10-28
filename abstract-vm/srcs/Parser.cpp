/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 20:03:08 by svelhinh          #+#    #+#             */
/*   Updated: 2017/05/31 12:41:11 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.hpp"
#include <regex>
#include <iostream>
#include <sstream>

Parser::Parser( void )
{
	return;
}

Parser::Parser( int ac, char **av )
{
	switch (ac)
	{
		case 1:
			parsing();
			break;
		case 2:
			parsing(av[1]);
			break;
		default:
		try
		{
			throw Exception::Exception("Too Many arguments");
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}

Parser::Parser( Parser const & src )
{
	*this = src;
	return;
}

Parser::~Parser( void )
{
	return;
}

Memory		Parser::getMemory( void ) const
{
	return _mem;
}

Parser & Parser::operator=( Parser const & rhs )
{
	_mem = rhs.getMemory();
	return *this;
}

void	Parser::parseStr(std::string str)
{
	std::list<std::string>	strList;
	_line = str;

	std::replace(str.begin(), str.end(), '\t', ' ');
	int pos = str.find(';');
	if (pos != -1)
		str = str.substr(0, pos);

	while (str.find(" ") != std::string::npos)
	{
		strList.push_back(str.substr(0, str.find(" ")));
		str.erase(0, str.find(" ") + 1);
	}
	strList.push_back(str);
	strList.remove("");

	// for (auto it : strList)
	// {
	// 	std::cout << it << std::endl;
	// }

	for (std::list<std::string>::const_iterator it = strList.begin(); it != strList.end(); ++it)
	{
		std::string strIt = *it;

		if (!strIt.compare("push"))
		{
			push(*std::next(it));
			++it;
		}
		else if (!strIt.compare("assert"))
		{
			assert(*std::next(it));
			++it;
		}
		else if (!strIt.compare("pop"))
			pop();
		else if (!strIt.compare("dump"))
			dump();
		else if (!strIt.compare("add"))
			add();
		else if (!strIt.compare("sub"))
			sub();
		else if (!strIt.compare("mul"))
			mul();
		else if (!strIt.compare("div"))
			div();
		else if (!strIt.compare("mod"))
			mod();
		else if (!strIt.compare("print"))
			print();
		else if (strIt.compare("exit"))
			throw Exception::Exception("Instruction not found", _nbLine, &_line);
	}
}

void	Parser::parseStrInput(std::string str)
{
	std::string buf, tmp_str = str;

	while (buf.compare(";;"))
	{
		buf = tmp_str.substr(0, tmp_str.find("\n"));
		tmp_str.erase(0, tmp_str.find("\n") + 1);
		_nbLine++;
		try
		{
			parseStr(buf);
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}

void	Parser::parsing(std::string filename)
{
	bool	readFromAFile = (!filename.empty()) ? (true) : (false);
	std::string buf;

	if (readFromAFile)
	{
		std::ifstream	ifs;
		try
		{
			if (filename.find("./") == -1ul)
				throw Exception::Exception("You must execute the file with ./");
			ifs.open(filename);
			if (!ifs)
				throw Exception::Exception((std::string("Can't open file ") + filename).c_str());
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
			exit(0);
		}

		while (buf.compare("exit") && !ifs.eof())
		{
			std::getline (ifs, buf);
			_nbLine++;
			try
			{
				parseStr(buf);
			}
			catch (std::exception & e)
			{
				std::cout << e.what() << std::endl;
			}
		}
		try
		{
			if (buf.compare("exit") && ifs.eof())
				throw Exception::Exception("The program doesn't have an exit instruction");
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	else
	{
		std::string str;
		while (buf.compare(";;"))
		{
			if (!std::getline (std::cin, buf))
				exit(0);
			str += buf + "\n";
		}
		parseStrInput(str);
	}
}

void	Parser::push(std::string str)
{
	std::smatch matches;
	eOperandType type = Int8;

	// Search all occurences of int8(...) or int16(...) or int32(...) or ...
	if (std::regex_search(str, matches, std::regex("int8\\(-*\\d+\\)")))
		type = Int8;
	else if (std::regex_search(str, matches, std::regex("int16\\(-*\\d+\\)")))
		type = Int16;
	else if (std::regex_search(str, matches, std::regex("int32\\(-*\\d+\\)")))
		type = Int32;
	else if (std::regex_search(str, matches, std::regex("float\\(-*\\d+\\.\\d+\\)")))
		type = Float;
	else if (std::regex_search(str, matches, std::regex("double\\(-*\\d+\\.\\d+\\)")))
		type = Double;

	// std::string sstr = str;
	// int pos = sstr.find(';');
	// if (pos != -1)
	// 	sstr = sstr.substr(0, pos);

	// If there is more than one occurence or we doesn't have exactly int8(...) or int16(...) or ...
	// So we throw an exception
	if (!(matches.size() == 1 && str.size() == static_cast<size_t>(matches[0].length())))
		throw Exception::Exception("Push Syntax Error", _nbLine, &str);

	// Get value to push to the stack with '()'
	std::regex_search(str, matches, std::regex("\\(-*[\\d|\\.]*\\)"));
	// Remove '()' from matches0
	std::string	matchStr = matches[0].str();
	matchStr.erase(std::remove(matchStr.begin(), matchStr.end(), '('), matchStr.end());
	matchStr.erase(std::remove(matchStr.begin(), matchStr.end(), ')'), matchStr.end());

	_mem.memPushFront(_init.createOperand(type, matchStr));
}

void	Parser::pop()
{
	if (_mem.getStack().empty())
		throw Exception::Exception("Pop on an empty stack", _nbLine);		
	else
		_mem.memPopFront();
}

void	Parser::dump() const
{
	std::list<IOperand const *>	stack = _mem.getStack();

	for (auto v : stack)
		std::cout << v->toString() << std::endl;
}

void	Parser::assert(std::string str) const
{
	std::smatch matches;

	// Search all occurences of int8(...) or int16(...) or int32(...) or ...
	// If there is more than one occurence or we doesn't have exactly int8(...) or int16(...) or ...
	// So we throw an exception
	if ((std::regex_search(str, matches, std::regex("int8\\(-*\\d+\\)")) ||
		std::regex_search(str, matches, std::regex("int16\\(-*\\d+\\)")) ||
		std::regex_search(str, matches, std::regex("int32\\(-*\\d+\\)")) ||
		std::regex_search(str, matches, std::regex("float\\(-*\\d+\\.\\d+\\)")) ||
		std::regex_search(str, matches, std::regex("double\\(-*\\d+\\.\\d+\\)"))))
	{
		if (!(matches.size() == 1 && str.size() == static_cast<size_t>(matches[0].length())))
			throw Exception::Exception("Assert Syntax Error", _nbLine, &str);
	}
	else
		throw Exception::Exception("Assert Syntax Error", _nbLine, &str);
	

	// Get value to assert with the top value of the stack with '()'
	std::regex_search(str, matches, std::regex("\\(-*[\\d|\\.]*\\)"));
	// Remove '()' from matches[0]
	std::string	matchStr = matches[0].str();
	matchStr.erase(std::remove(matchStr.begin(), matchStr.end(), '('), matchStr.end());
	matchStr.erase(std::remove(matchStr.begin(), matchStr.end(), ')'), matchStr.end());

	if (_mem.getStack().empty())
		throw Exception::Exception("Assert Empty Stack", _nbLine);
	std::stringstream	ss1(matchStr), ss2(_mem.getStack().front()->toString());
	long double			val1, val2;

	ss1 >> val1;
	ss2 >> val2;
	if (val1 != val2)
	{
		std::ostringstream	oss;

		oss << "\033[34mAssert : \033[31m" << matchStr << " != " + _mem.getStack().front()->toString();
		throw Exception::Exception(oss.str().c_str());
	}
}

void	Parser::add()
{
	if (_mem.getStack().size() < 2)
		throw Exception::Exception("\033[36mAdd :\033[31m Stack has less than 2 operands", _nbLine);
	IOperand const *n1 = _mem.getStack().front();
	_mem.memPopFront();
	IOperand const *n2 = _mem.getStack().front();
	_mem.memPopFront();
	IOperand const *res = *n1 + *n2;
	_mem.memPushFront(res);
}

void	Parser::sub()
{
	if (_mem.getStack().size() < 2)
		throw Exception::Exception("\033[36mSub :\033[31m Stack has less than 2 operands", _nbLine);
	IOperand const *n1 = _mem.getStack().front();
	_mem.memPopFront();
	IOperand const *n2 = _mem.getStack().front();
	_mem.memPopFront();
	IOperand const *res = *n1 - *n2;
	_mem.memPushFront(res);
}

void	Parser::mul()
{
	if (_mem.getStack().size() < 2)
		throw Exception::Exception("\033[36mMul :\033[31m Stack has less than 2 operands", _nbLine);
	IOperand const *n1 = _mem.getStack().front();
	_mem.memPopFront();
	IOperand const *n2 = _mem.getStack().front();
	_mem.memPopFront();
	IOperand const *res = *n1 * *n2;
	_mem.memPushFront(res);
}

void	Parser::div()
{
	if (_mem.getStack().size() < 2)
		throw Exception::Exception("\033[36mDiv :\033[31m Stack has less than 2 operands", _nbLine);
	IOperand const *n1 = _mem.getStack().front();
	IOperand const *n2 = *std::next(_mem.getStack().begin());
	IOperand const *res = *n1 / *n2;
	_mem.memPopFront();
	_mem.memPopFront();
	_mem.memPushFront(res);
}

void	Parser::mod()
{
	if (_mem.getStack().size() < 2)
		throw Exception::Exception("\033[36mMod :\033[31m Stack has less than 2 operands", _nbLine);
	IOperand const *n1 = _mem.getStack().front();
	IOperand const *n2 = *std::next(_mem.getStack().begin());
	IOperand const *res = *n1 % *n2;
	_mem.memPopFront();
	_mem.memPopFront();
	_mem.memPushFront(res);
}

void	Parser::print()
{
	std::ostringstream	oss;
	if (_mem.getStack().empty())
		throw Exception::Exception("Print Empty Stack", _nbLine);
	if (_mem.getStack().front()->getType() != Int8)
	{
		oss << "\033[34mPrint : \033[31m" << _mem.getStack().front()->toString() << " is not an int8";
		throw Exception::Exception(oss.str().c_str());
	}
	char val = atoi(_mem.getStack().front()->toString().c_str());

	if (val < 0)
	{
		oss << "\033[34mPrint : \033[31m" << _mem.getStack().front()->toString() << " is not a valid ascii character";
		throw Exception::Exception(oss.str().c_str());
	}

	std::cout << val << std::endl;
}