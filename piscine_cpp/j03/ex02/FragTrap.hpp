#ifndef FragTrap_hpp
#define FragTrap_hpp

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
	FragTrap(std::string const name);
	FragTrap(FragTrap const &src, std::string const name);
	~FragTrap();

	void			rangedAttack(std::string const & target);
	void			meleeAttack(std::string const & target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
	void			vaulthunter_dot_exe(std::string const & target);

	FragTrap & operator = ( FragTrap const & rhs );
};


#endif
