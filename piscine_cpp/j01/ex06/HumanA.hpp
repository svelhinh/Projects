/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 17:45:17 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/04 18:46:31 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA
{
public:
	HumanA(std::string name_, Weapon &weapon_);
	HumanA(std::string name_);
    ~HumanA();

	void	attack() const;
	void	setWeapon(Weapon &weapon);

private:
	Weapon		*weapon;
	std::string	name;
};


#endif
