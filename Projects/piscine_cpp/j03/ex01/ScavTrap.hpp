/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 14:55:53 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/06 19:26:12 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <string>

class ScavTrap
{
public:
	ScavTrap(void);
    ScavTrap(std::string name);
	ScavTrap(ScavTrap const & src);
    ~ScavTrap();

	void	rangedAttack(std::string const & target);
	void	meleeAttack(std::string const & target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void	challengeNewcomer();

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

	ScavTrap &		operator=( ScavTrap const & rhs );

private:
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
