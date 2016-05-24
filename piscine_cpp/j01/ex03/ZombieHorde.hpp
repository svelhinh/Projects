#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP
#include "Zombie.hpp"
#include <time.h>
#include <stdlib.h>

class ZombieHorde
{
public:
	ZombieHorde(int N);
	~ZombieHorde(void);
private:
	int const _N;
	Zombie *_zombies;
};

#endif
