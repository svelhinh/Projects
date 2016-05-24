#include "Human.hpp"

Human::Human(void)
{
    Brain *t = new Brain();
	this->brain = *t;
}

Human::~Human(void)
{
    return;
}

Brain Human::getBrain(void)
{
    return this->brain;
}

std::string Human::identify(void)
{
    return this->brain.identify();
}
