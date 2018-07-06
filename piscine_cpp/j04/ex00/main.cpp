/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 13:58:27 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/07 18:35:47 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"
#include "Goat.hpp"
#include <iostream>

int main()
{
	Sorcerer robert("Robert", "the Magnificent");
	Victim jim("Jimmy");
	Peon joe("Joe");
	Goat toto("Toto");
	Goat bob("Bob");

	std::cout << robert << jim << joe << toto << bob;
	robert.polymorph(jim);
	robert.polymorph(joe);
	robert.polymorph(toto);
	robert.polymorph(bob);
	return 0;
}
