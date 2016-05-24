#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>

class Brain
{
public:
	std::string addr;
	Brain(void);
	~Brain(void);
	std::string	identify(void);
};

#endif
