/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Event.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 17:01:48 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/09 20:39:04 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ncurses.h>
#include "Event.hpp"

Event::Event(void)
{
}

Event::Event(Event const & src)
{
	*this = src;
	return;
}

Event::~Event(void)
{
}

Event & Event::operator = (Event const & rhs)
{
	(void)rhs;
	return *this;
}

void Event::update(void)
{
	int key;

	for (int i = 0; i < K_NKEYS; i++)
		_keys[i] = false;

	while (1) {
		key = getch();

		if (key == ERR)
			break;

		switch (key) {
			case 'w': case KEY_UP:
				_keys[K_UP] = true;
				break;
			case 's': case KEY_DOWN:
				_keys[K_DOWN] = true;
				break;
			case 'd': case KEY_RIGHT:
				_keys[K_RIGHT] = true;
				break;
			case 'a': case KEY_LEFT:
				_keys[K_LEFT] = true;
				break;
			case ' ':
				_keys[K_SHOOT] = true;
				break;
			case '\033':
				_keys[K_ESC] = true;
				break;
			default:
				break;
		}
	}
}

bool Event::isPressed(int key) const
{
	if (key < 0 || key >= K_NKEYS)
		return false;
	else
		return _keys[key];
}
