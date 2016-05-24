#include "Zombie.hpp"

Zombie::Zombie(void)
{
    return;
}

Zombie::~Zombie(void)
{
    return;
}

std::string Zombie::getName(void)
{
	return (this->_name);
}

std::string Zombie::getType(void)
{
	return (this->_type);
}

void Zombie::setName(std::string name)
{
	this->_name = name;
}

void Zombie::setType(std::string type)
{
	this->_type = type;
}

void	Zombie::announce(void)
{
	std::cout << "<" << this->getName() << " (" << this->getType() << ")> Braiiiiiiinnnssss..." << std::endl;
}
