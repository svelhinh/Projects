#ifndef ScavTrap_hpp
#define ScavTrap_hpp

#include <iostream>
#include <stdlib.h>

class ScavTrap
{
private:
	int					_hit_points;
	int					_max_hit_points;
	int					_energy_points;
	int					_max_energy_points;
	int					_level;
	std::string			_name;
	int					_melee_attack_damage;
	int					_ranged_attack_damage;
	int					_armor_damage_reduction;

public:
	ScavTrap(std::string const name);
	ScavTrap(ScavTrap const &src, std::string const name);
	~ScavTrap();

	void			rangedAttack(std::string const & target);
	void			meleeAttack(std::string const & target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
	void			challengeNewcomer(std::string const & target);

	int				getHitPoints() const;
	int				getMaxHitPoints() const;
	int				getEnergyPoints() const;
	int				getMaxEnergyPoints() const;
	int				getLevel() const;
	std::string		getName() const;
	int				getMeleeAttackDamage() const;
	int				getRangedAttackDamage() const;
	int				getArmorDamageReduction() const;

	void			setHitPoints(const int hp);
	void			setEnergyPoints(int const ep);

	ScavTrap & operator = ( ScavTrap const & rhs );
};


#endif
