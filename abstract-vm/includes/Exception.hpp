#ifndef Exception_hpp
#define Exception_hpp

#include <list>
#include <string>
#include <cstdarg>

typedef void (*func_t)(va_list);

class Exception : public std::exception
{
public:
	Exception( void );
	Exception(const char * msg, int line = -1, std::string *instr = NULL);
	Exception(Exception const &rhs);
	virtual ~Exception() throw();

	const char	*getMsg() const;
	int			getLine() const;
	std::string	*getInstr() const;
	void		finalMessage() throw();

	Exception	&operator=(Exception const &rhs);

	virtual const char* what() const throw ();

private:
	const char	*_msg;
	std::string	_msgFinal;
	int			_line;
	std::string	*_instr;
};

#endif
