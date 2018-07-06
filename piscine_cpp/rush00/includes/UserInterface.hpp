/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserInterface.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 13:24:59 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/09 19:21:36 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UserInterface_hpp
#define UserInterface_hpp
#include <string>

enum e_colors
{
    C_REDBLACK = 1,
    C_BLUEBLACK = 2,
    C_WHITEBLACK = 3,
    C_GREENBLACK = 4,
    C_YELLOWBLACK = 5,
    C_CYANBLACK = 6
};

void mvprintwColor(int x, int y, std::string str, int color);
void mvprintcColor(int x, int y, char c, int color);

class UserInterface
{
public:
	UserInterface(void);
    UserInterface(UserInterface const & src);
    virtual ~UserInterface(void);

	void	update(int nbLives, int score, int time, int level) const;

private:
    void	displayInfos(int nbLives, int score, int time, int level) const;

	UserInterface &	operator=( UserInterface const & rhs );
};


#endif /* UserInterface_hpp */
