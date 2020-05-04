/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:01:24 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/05 19:48:20 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"
#include <iostream>
#include <iomanip>

Pony::Pony(std::string const name_, int const color_, float const height_): name(name_), color(color_), height(height_)
{
	return;
}

Pony::~Pony()
{
	return;
}

void	ponyOnTheHeap(std::string const name, int const color, float const height)
{
	Pony	*pony = new Pony(name, color, height);

	std::cout << "Pony on the heap : " << pony->name << ", 0x" << std::setbase(16) << pony->color << ", " << pony->height << std::endl;
	delete pony;
}

void	ponyOnTheStack(std::string const name, int const color, float const height)
{
	Pony	pony = Pony(name, color, height);

	std::cout << "Pony on the stack : " << pony.name << ", 0x" << std::setbase(16) << pony.color << ", " << pony.height << std::endl;
}
