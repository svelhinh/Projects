#ifndef ClapTrap_hpp
#define ClapTrap_hpp

#include <iostream>
#include <stdlib.h>

class ClapTrap
{
protected:
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
	ClapTrap(std::string const name);
	ClapTrap(ClapTrap const &src, std::string const name);
	~ClapTrap();

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

	ClapTrap & operator = ( ClapTrap const & rhs );
};


#endif
