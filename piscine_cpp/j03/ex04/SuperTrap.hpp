#ifndef SuperTrap_hpp
#define SuperTrap_hpp

#include "FragTrap.hpp"
#include "NinjaTrap.hpp"

class SuperTrap : public FragTrap, public NinjaTrap
{
public:
	SuperTrap(std::string const name);
	SuperTrap(SuperTrap const &src, std::string const name);
	~SuperTrap();

	SuperTrap & operator = ( SuperTrap const & rhs );
};


#endif
