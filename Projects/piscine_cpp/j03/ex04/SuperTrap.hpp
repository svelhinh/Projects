/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 11:15:32 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/07 12:10:58 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP

# include <string>
# include "FragTrap.hpp"
# include "NinjaTrap.hpp"

class SuperTrap : public FragTrap, public NinjaTrap
{
public:
	SuperTrap(void);
    SuperTrap(std::string name);
	SuperTrap(SuperTrap const & src);
    ~SuperTrap();

    using FragTrap::rangedAttack;
    using FragTrap::vaulthunter_dot_exe;
    using NinjaTrap::meleeAttack;
    using NinjaTrap::ninjaShoebox;

	SuperTrap &		operator=( SuperTrap const & rhs );
};


#endif
