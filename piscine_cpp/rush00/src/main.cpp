#include <ncurses.h>
#include <iostream>
#include <ncurses.h>
#include "Game.hpp"

int main(void)
{
	Game g;

	srand(time(NULL));
	initscr();
	start_color();
	curs_set(0);
	timeout(0);
	noecho();
	keypad(stdscr, TRUE);

	init_pair(C_BLUEBLACK, COLOR_BLACK, COLOR_BLUE);
	init_pair(C_REDBLACK, COLOR_RED, COLOR_BLACK);
	init_pair(C_WHITEBLACK, COLOR_WHITE, COLOR_BLACK);
	init_pair(C_GREENBLACK, COLOR_GREEN, COLOR_BLACK);
	init_pair(C_YELLOWBLACK, COLOR_YELLOW, COLOR_BLACK);
	init_pair(C_CYANBLACK, COLOR_CYAN, COLOR_BLACK);

	g.start();

	endwin();

	return 0;
}
