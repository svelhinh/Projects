#include "ZombieEvent.hpp"

int main(void)
{
	ZombieEvent zombie1;
	ZombieEvent zombie2;
	ZombieEvent zombie3;
	ZombieEvent zombie4;
	ZombieEvent zombie_random;
	Zombie *bob;
	Zombie *jim;
	Zombie *toto;
	Zombie *tata;

	zombie1.setZombieType("Stalker");
	zombie2.setZombieType("Stalker");
	zombie3.setZombieType("Tank");
	zombie4.setZombieType("Tank");
	zombie_random.setZombieType("Shilter");
	bob = zombie1.newZombie("Bob");
	jim = zombie2.newZombie("Jim");
	toto = zombie3.newZombie("Toto");
	tata = zombie4.newZombie("Tata");
	zombie_random.randomChump();
	bob->announce();
	jim->announce();
	toto->announce();
	tata->announce();
	delete bob;
	delete jim;
	delete toto;
	delete tata;
	return 0;
}
