#ifndef PONY_HPP
# define PONY_HPP
# include <iostream>

class Pony
{
public:
	Pony(std::string name, int color, double height);
	~Pony(void);
	std::string const	name;
	int const			color;
	double const		height;
};
Pony ponyOnTheStack(std::string name, int color, double height);
Pony *ponyOnTheHeap(std::string name, int color, double height);

#endif
