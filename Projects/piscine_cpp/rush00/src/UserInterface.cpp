/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserInterface.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 13:25:27 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/09 18:57:53 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "UserInterface.hpp"
#include "Game.hpp"

UserInterface::UserInterface(void)
{
}

UserInterface::UserInterface(UserInterface const & src)
{
	*this = src;
	return;
}

UserInterface::~UserInterface(void)
{
}

void	UserInterface::displayInfos(int nbLives, int score, int time, int level) const
{
	int width = MAPL;
	int height = 2;
	float nbInfos = 4;

	for (int x = 0; x <= width; x++)
		mvprintwColor(MAPH + height, x, " ", C_BLUEBLACK);
	for (float i = nbInfos; i >= 0; i--)
		for (int y = MAPH + 1; y < MAPH + height; y++)
			mvprintwColor(y, i / nbInfos * width, " ", C_BLUEBLACK);

	int y = MAPH + height;

	mvprintw(y - 1, (((nbInfos - 1) / nbInfos * width) + ((nbInfos / nbInfos * width - (nbInfos - 1) / nbInfos * width) / 2)) - 2.5, std::string(std::string("LIVES : ") + std::to_string(nbLives)).c_str());
	mvprintw(y - 1, (((nbInfos - 2) / nbInfos * width) + (((nbInfos - 1) / nbInfos * width - (nbInfos - 2) / nbInfos * width) / 2)) - 2.5, std::string(std::string("SCORE : ") + std::to_string(score)).c_str());
	mvprintw(y - 1, (((nbInfos - 3) / nbInfos * width) + (((nbInfos - 2) / nbInfos * width - (nbInfos - 3) / nbInfos * width) / 2)) - 2.5, std::string(std::string("LEVEL : ") + std::to_string(level)).c_str());
	mvprintw(y - 1, (((nbInfos - 4) / nbInfos * width) + (((nbInfos - 3) / nbInfos * width - (nbInfos - 4) / nbInfos * width) / 2)) - 2, std::string(std::string("TIME : ") + std::to_string(time)).c_str());
}

void	UserInterface::update(int nbLives, int score, int time, int level) const
{
	for (int y = 0; y <= MAPL; y++)
	{
		mvprintwColor(0, y, " ", C_BLUEBLACK);
		mvprintwColor(MAPH, y, " ", C_BLUEBLACK);
	}
	for (int x = 0; x <= MAPH; x++)
	{
		mvprintwColor(x, 0, " ", C_BLUEBLACK);
		mvprintwColor(x, MAPL, " ", C_BLUEBLACK);
	}
	displayInfos(nbLives, score, time, level);
}

UserInterface &	UserInterface::operator=( UserInterface const & rhs )
{
	(void)rhs;
	return *this;
}

void	mvprintwColor(int x, int y, std::string str, int color)
{
	attron(A_BOLD);
	wattron(stdscr, COLOR_PAIR(color));
	mvprintw(x, y, str.c_str());
	wattroff(stdscr, COLOR_PAIR(color));
	attroff(A_BOLD);
}

void	mvprintcColor(int x, int y, char c, int color)
{
	attron(A_BOLD);
	wattron(stdscr, COLOR_PAIR(color));
	mvprintw(x, y, "%c", c);
	wattroff(stdscr, COLOR_PAIR(color));
	attroff(A_BOLD);
}
