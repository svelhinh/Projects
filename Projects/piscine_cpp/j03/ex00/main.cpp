/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 11:15:59 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/06 13:55:30 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <cstdlib>

int	main()
{
	srand(time(NULL));

	FragTrap	bob = FragTrap("bob");
	FragTrap	jim = FragTrap("jim");

	bob.rangedAttack(jim.getName());
	bob.meleeAttack(jim.getName());
	bob.takeDamage(20);
	bob.beRepaired(12);
	jim.vaulthunter_dot_exe(bob.getName());
	for(int i = 0; i < 6; i++)
		bob.vaulthunter_dot_exe(jim.getName());
	return 0;
}
