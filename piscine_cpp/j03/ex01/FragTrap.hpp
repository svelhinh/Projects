/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 11:15:32 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/06 19:26:03 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <string>

class FragTrap
{
public:
	FragTrap(void);
    FragTrap(std::string name);
	FragTrap(FragTrap const & src);
    ~FragTrap();

	void	rangedAttack(std::string const & target);
	void	meleeAttack(std::string const & target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void	vaulthunter_dot_exe(std::string const & target);

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

	FragTrap &		operator=( FragTrap const & rhs );

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
