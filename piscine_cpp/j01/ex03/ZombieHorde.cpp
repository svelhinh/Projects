#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int _N): _N(_N)
{
    this->_zombies = new Zombie[_N];
	srand(time(NULL));
	for (int i = 0; i < _N; i++)
	{
		size_t name_size = 3 + (rand() % (10 - 3));
		std::string name;
		char letter = 'A' + (rand() % ('Z' - 'A'));

		name = name + letter;
		for (size_t j = 1; j < name_size; j++)
		{
			letter = 'a' + (rand() % ('z' - 'a'));
			name = name + letter;
		}
		this->_zombies[i].setName(name);
	    this->_zombies[i].setType("Tank");
		this->_zombies[i].announce();
	}
    return;
}

ZombieHorde::~ZombieHorde(void)
{
	delete [] this->_zombies;
    return;
}
