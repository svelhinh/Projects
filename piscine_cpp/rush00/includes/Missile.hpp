/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Missile.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 13:24:59 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/09 16:24:06 by nchrupal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Missile_hpp
#define Missile_hpp

#include "AHitBox.hpp"
#include <string>

class Missile : public AHitBox
{
public:
	Missile(void);
	Missile(int x, int y);
    Missile(Missile const & src);
    virtual ~Missile(void);

	void	draw(void);
	void	move(int x, int y);

	void	update(void);

	Missile &	operator=( Missile const & rhs );

private:
	std::string	const _shape;
};


#endif /* Missile_hpp */
