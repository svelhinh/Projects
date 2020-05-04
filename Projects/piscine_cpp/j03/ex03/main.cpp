/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 11:15:59 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/06 16:17:00 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include <cstdlib>
#include <iostream>

int	main()
{
	srand(time(NULL));

	// FRAGTRAP
	std::cout << "\033[93mFR4G-TP :\033[94m" << std::endl << std::endl;

	FragTrap	bob = FragTrap("bob");
	FragTrap	jim = FragTrap("jim");

	bob.rangedAttack(jim.getName());
	bob.meleeAttack(jim.getName());
	bob.takeDamage(20);
	bob.beRepaired(12);
	jim.vaulthunter_dot_exe(bob.getName());
	for(int i = 0; i < 6; i++)
		bob.vaulthunter_dot_exe(jim.getName());



	std::cout << std::endl << std::endl;



	// SCAVTRAP
	std::cout << "\033[93mSC4V-TP :\033[94m" << std::endl << std::endl;

	ScavTrap	toto = ScavTrap("toto");
	ScavTrap	tata = ScavTrap("tata");

	toto.rangedAttack(tata.getName());
	toto.meleeAttack(tata.getName());
	toto.takeDamage(12);
	toto.beRepaired(20);
	tata.challengeNewcomer();
	toto.challengeNewcomer();



	std::cout << std::endl << std::endl;



	// NINJATRAP
	std::cout << "\033[93mNINJ4-TP :\033[94m" << std::endl << std::endl;

	NinjaTrap	riri = NinjaTrap("riri");
	NinjaTrap	roro = NinjaTrap("roro");

	riri.rangedAttack(roro.getName());
	riri.meleeAttack(roro.getName());
	riri.takeDamage(12);
	riri.beRepaired(20);
	roro.ninjaShoebox(bob);
	riri.ninjaShoebox(toto);
	roro.ninjaShoebox(riri);
	return 0;
}
