#ifndef ScavTrap_hpp
#define ScavTrap_hpp

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap(std::string const name);
	ScavTrap(ScavTrap const &src, std::string const name);
	~ScavTrap();

	void			rangedAttack(std::string const & target);
	void			meleeAttack(std::string const & target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
	void			challengeNewcomer(std::string const & target);

	ScavTrap & operator = ( ScavTrap const & rhs );
};


#endif
