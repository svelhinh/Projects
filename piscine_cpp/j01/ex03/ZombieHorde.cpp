/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 14:13:35 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/04 14:57:27 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int N): hordeSize(N)
{
	this->zombies = new Zombie[N];
	srand (time(NULL));
	for(int i = 0; i < N; i++)
	{
		size_t nameSize = 3 + (std::rand() % (10 - 3 + 1));
		std::string name;
		char letter = 'A' + (rand() % ('Z' - 'A'));

		name += letter;
		for (size_t i = 1; i < nameSize; i++)
		{
			letter = 'a' + (rand() % ('z' - 'a'));
			name += letter;
		}
		zombies[i].name = name;
		zombies[i].type = "Runner";
	}
	return;
}

ZombieHorde::~ZombieHorde()
{
	delete [] this->zombies;
	return;
}

void	ZombieHorde::announce()
{
	for (int i = 0; i < this->hordeSize; i++)
		zombies[i].announce();
}
