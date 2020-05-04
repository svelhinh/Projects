/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 15:25:30 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/07 12:05:42 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class ClapTrap
{
public:
	ClapTrap(void);
    ClapTrap(std::string name);
	ClapTrap(ClapTrap const & src);
    ~ClapTrap();

	void	rangedAttack(std::string const & target);
	void	meleeAttack(std::string const & target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	unsigned int	getHitPoints() const;
	unsigned int	getMaxHitPoints() const;
	unsigned int	getEnergyPoints() const;
	unsigned int	getMaxEnergyPoints() const;
	unsigned int	getLevel() const;
	std::string		getName() const;
	unsigned int	getMeleeAttackDamage() const;
	unsigned int	getRangedAttackDamage() const;
	unsigned int	getArmorDamageReduction() const;

	void			setHitPoints( int const hitPoints_ );
	void			setMaxHitPoints( int const maxHitPoints_ );
	void			setEnergyPoints( int const energyPoints_ );
	void			setMaxEnergyPoints( int const maxEnergyPoints_ );
	void			setLevel( int const level_ );
	void			setName( std::string const name_ );
	void			setMeleeAttackDamage( int const meleeAttackDamage_ );
	void			setRangedAttackDamage( int const rangedAttackDamage_ );
	void			setArmorDamageReduction( int const armorDamageReduction_ );

	ClapTrap &		operator=( ClapTrap const & rhs );

protected:
	unsigned int	hitPoints;
	unsigned int	maxHitPoints;
	unsigned int	energyPoints;
	unsigned int	maxEnergyPoints;
	unsigned int	level;
	std::string		name;
	unsigned int	meleeAttackDamage;
	unsigned int	rangedAttackDamage;
	unsigned int	armorDamageReduction;
};


#endif
