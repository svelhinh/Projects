#ifndef NinjaTrap_hpp
#define NinjaTrap_hpp

#include "ClapTrap.hpp"

class NinjaTrap : public ClapTrap
{
public:
	NinjaTrap(std::string const name);
	NinjaTrap(NinjaTrap const &src, std::string const name);
	~NinjaTrap();

	void			rangedAttack(std::string const & target);
	void			meleeAttack(std::string const & target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
	void			ninjaShoebox(std::string const & target);

	NinjaTrap & operator = ( NinjaTrap const & rhs );
};


#endif
