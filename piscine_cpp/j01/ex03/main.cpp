/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 14:33:27 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/04 15:03:41 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

int main()
{
	ZombieHorde	zombieH = ZombieHorde(3);
	ZombieHorde	zombieH2 = ZombieHorde(20);
	ZombieHorde	zombieH3 = ZombieHorde(2);

	zombieH.announce();
	zombieH2.announce();
	zombieH3.announce();
	return 0;
}
