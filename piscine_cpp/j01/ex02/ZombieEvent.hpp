#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP
#include "Zombie.hpp"
#include <time.h>
#include <stdlib.h>

class ZombieEvent
{
public:
	ZombieEvent(void);
	~ZombieEvent(void);
	void	setZombieType(std::string type);
	Zombie* newZombie(std::string name);
	void	randomChump(void);
private:
	std::string		_type;
};

#endif
