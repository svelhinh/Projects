#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent(void)
{
    return;
}

ZombieEvent::~ZombieEvent(void)
{
    return;
}

void	ZombieEvent::setZombieType(std::string type)
{
    this->_type = type;
}

Zombie* ZombieEvent::newZombie(std::string name)
{
    Zombie *zombie = new Zombie();
    zombie->setName(name);
    zombie->setType(this->_type);
    return zombie;
}

void	ZombieEvent::randomChump(void)
{
	srand (time(NULL));
	size_t name_size = 3 + (rand() % (10 - 3));
	std::string name;
	char letter = 'A' + (rand() % ('Z' - 'A'));

	name = name + letter;
	for (size_t i = 1; i < name_size; i++)
	{
		letter = 'a' + (rand() % ('z' - 'a'));
		name = name + letter;
	}
	Zombie *zombie = newZombie(name);
    zombie->announce();
	delete zombie;
}
