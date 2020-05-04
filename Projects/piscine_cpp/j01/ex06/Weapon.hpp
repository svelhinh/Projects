/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 17:47:41 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/04 18:34:48 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Weapon_hpp
# define Weapon_hpp

# include <string>

class Weapon
{
public:
	Weapon(std::string type_);
	~Weapon();

	std::string const	&getType() const;
	void		setType(std::string type);

private:
	std::string	type;
};


#endif
