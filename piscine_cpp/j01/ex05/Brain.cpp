#include "Brain.hpp"
#include <sstream>

Brain::Brain(void)
{
	std::stringstream addr;

	addr << std::hex << this;
	this->addr = addr.str();
    return;
}

Brain::~Brain(void)
{
    return;
}

std::string Brain::identify(void)
{
    return this->addr;
}
