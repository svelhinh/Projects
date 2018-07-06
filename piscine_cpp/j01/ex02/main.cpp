/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:25:01 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/04 14:45:25 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

void	randomChump()
{
	srand (time(NULL));
	size_t nameSize = 3 + (std::rand() % (10 - 3 + 1));
	std::string name;
	char letter = 'A' + (rand() % ('Z' - 'A'));

	name += letter;
	for (size_t i = 1; i < nameSize; i++)
	{
		letter = 'a' + (rand() % ('z' - 'a'));
		name += letter;
	}

	Zombie zombie = Zombie();
	zombie.name = name;
	zombie.type = "Runner";
    zombie.announce();
}

int main()
{
	ZombieEvent zombie1;
	ZombieEvent zombie2;
	ZombieEvent zombie3;
	ZombieEvent zombie4;
	Zombie *bob;
	Zombie *jim;
	Zombie *toto;
	Zombie *tata;

	zombie1.setZombieType("Stalker");
	zombie2.setZombieType("Stalker");
	zombie3.setZombieType("Tank");
	zombie4.setZombieType("Tank");
	bob = zombie1.newZombie("Bob");
	jim = zombie2.newZombie("Jim");
	toto = zombie3.newZombie("Toto");
	tata = zombie4.newZombie("Tata");
	randomChump();
	bob->announce();
	delete bob;
	jim->announce();
	delete jim;
	toto->announce();
	delete toto;
	tata->announce();
	delete tata;
	return 0;
}
