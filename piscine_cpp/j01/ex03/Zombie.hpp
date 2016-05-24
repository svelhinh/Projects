#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>

class Zombie
{
public:
	Zombie(void);
	~Zombie(void);
	void	announce(void);
	std::string	getName(void);
	void	setName(std::string name);
	std::string	getType(void);
	void	setType(std::string type);
private:
	std::string	_name;
	std::string	_type;
};

#endif
