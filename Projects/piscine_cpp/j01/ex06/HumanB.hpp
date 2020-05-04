/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 17:46:02 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/04 18:46:31 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
public:
	HumanB(std::string name_, Weapon *weapon_);
	HumanB(std::string name_);
    ~HumanB();

	void	attack() const;
	void	setWeapon(Weapon &weapon);

private:
	Weapon		*weapon;
	std::string	name;
};


#endif
