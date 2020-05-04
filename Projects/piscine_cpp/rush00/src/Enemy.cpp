/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 13:25:27 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/09 20:36:36 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"
#include "Game.hpp"
#include <cstdlib>

// std::string enemiesShapes[] = {
// 	"                                                 /===-_---~~~~~~~~~------____\n                                                |===-~___                _,-'\n                 -==\\\\                         `//~\\\\   ~~~~`---.___.-~~\n             ______-==|                         | |  \\\\           _-~`\n       __--~~~  ,-/-==\\\\                        | |   `\\        ,'\n    _-~       /'    |  \\\\                      / /      \\      /\n  .'        /       |   \\\\                   /' /        \\   /'\n /  ____  /         |    \\`\\.__/-~~ ~ \\ _ _/'  /          \\/'\n/-'~    ~~~~~---__  |     ~-/~         ( )   /'        _--~`\n                  \\_|      /        _)   ;  ),   __--~~\n                    '~~--_/      _-~/-  / \\   '-~ \\\n                   {\\__--_/}    / \\\\_>- )<__\\      \\\n                   /'   (_/  _-~  | |__>--<__|      |\n                  |0  0 _/) )-~     | |__>--<__|     |\n                  / /~ ,_/       / /__>---<__/      |\n                 o o _//        /-~_>---<__-~      /\n                 (^(~          /~_>---<__-      _-~\n                              /__>--<__/     _-~\n                             |__>--<__|     /                  .----_\n                             |__>--<__|    |                 /' _---_~\\\n                             |__>--<__|    |               /'  /     ~\\`\\\n                              \\__>--<__\\    \\            /'  //        ||\n                               ~-__>--<_~-_  ~--____---~' _/'/        /'\n                                 ~-_~>--<_/-__       __-~ _/\n                                     ~~-'_/_/ /~~~~~~~__--~\n                                            ~~~~~~~~~~",
// };

Enemy::Enemy(void)
	: ACharacter(1, 1, 1, 2, 2, "@@\n@@", C_WHITEBLACK), _elapsedTicks(0)
{
}

Enemy::Enemy(int pv, int x, int y, int givenScore, int color)
	: ACharacter(pv, x, y, 2, 2, "@@\n@@", color), _elapsedTicks(0), _givenScore(givenScore)
{
	struct {
		int w, h;
		std::string s;
	} tab[] = {
		{ 2, 2, "@@\n@@" },
		{ 3, 3, "\\o/\n |\n/ \\" },
		{ 3, 7, " /   \\\n|--o--|\n \\   /" },
		{ 3, 4, "  \\/\n---\n  /\\" }
	};
	int sz = sizeof(tab) / sizeof(*tab);
	int random = rand() % sz;

	_h = tab[random].h;
	_w = tab[random].w;
	_shape = tab[random].s;
}

Enemy::Enemy(Enemy const & src)
{
	*this = src;
	return;
}

Enemy::~Enemy(void)
{
}

int			Enemy::getGivenScore(void) const
{
	return _givenScore;
}

void	Enemy::update(void)
{
	_elapsedTicks++;
	// vitesse: niveau 0 -> 0.5s : 30 ticks
	if (_elapsedTicks < _speedLevel + rand() % 10)
		return;
	_elapsedTicks = 0;
	int y = -1 + (rand() % 3);
	while (_y + y <= 0 || _y + y >= MAPH)
		y = -1 + (rand() % 3);
	move(-1, y);
}

void		Enemy::setSpeedLevel(int level)
{
	static enum e_speedLevels tab[] = {
		e_speedLvl0,
		e_speedLvl1,
		e_speedLvl2,
		e_speedLvl3,
	};

	_speedLevel = tab[level];
}

void	Enemy::shoot(void)
{
}

void	Enemy::takeDamage(int amount)
{
	_pv -= amount;
}

Enemy &	Enemy::operator=( Enemy const & rhs )
{
	_pv = rhs.getPv();
	return *this;
}
