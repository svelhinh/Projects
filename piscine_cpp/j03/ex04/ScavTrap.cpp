#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string const name): ClapTrap(name)
{
	std::cout << "\033[34mScavTrap " << name << " created\033[0m" << std::endl;
	return;
}

ScavTrap::ScavTrap(ScavTrap const & src, std::string const name): ClapTrap(name)
{
	*this = src;
	std::cout << "ScavTrap " << name << " created by copy" << std::endl;
	return;
}

ScavTrap::~ScavTrap()
{
	std::cout << "\033[31mScavTrap " << this->getName() << " destructed\033[0m" << std::endl;
	return;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & rhs)
{
	this->_hit_points = rhs.getHitPoints();
	this->_max_hit_points = rhs.getMaxHitPoints();
	this->_energy_points = rhs.getEnergyPoints();
	this->_max_energy_points = rhs.getMaxEnergyPoints();
	this->_level = rhs.getLevel();
	this->_name = rhs.getName();
	this->_melee_attack_damage = rhs.getMeleeAttackDamage();
	this->_ranged_attack_damage = rhs.getRangedAttackDamage();
	this->_armor_damage_reduction = rhs.getArmorDamageReduction();
	return *this;
}

void			ScavTrap::rangedAttack(std::string const & target)
{
	std::cout << "SC4V-TP " << this->getName() << " attacks "
	<< target << " at range, causing " << this->getRangedAttackDamage()
	<< " points of damage !" << std::endl;
}

void			ScavTrap::meleeAttack(std::string const & target)
{
	std::cout << "SC4V-TP " << this->getName() << " attacks "
	<< target << " at melee, causing " << this->getRangedAttackDamage()
	<< " points of damage !" << std::endl;
}

void			ScavTrap::takeDamage(unsigned int amount)
{
	int life = this->getHitPoints();
	int shield = this->getArmorDamageReduction();

	if (life + shield - (int)amount > 0)
	{
		this->setHitPoints(life + shield - amount);
		std::cout << "SC4V-TP " << this->getName() << " takes "
		<< amount << " points of damage !" << std::endl;
	}
	else
	{
		this->setHitPoints(0);
		std::cout << "SC4V-TP " << this->getName() << " is dead" << std::endl;
	}
}

void			ScavTrap::beRepaired(unsigned int amount)
{
	unsigned int life = this->getHitPoints();
	unsigned int max = this->getMaxHitPoints();

	if (life + amount <= max)
		this->setHitPoints(life + amount);
	else
		this->setHitPoints(max);
	std::cout << "SC4V-TP " << this->getName() << " has "
	<< this->getHitPoints() << " HP" << std::endl;
}

void			ScavTrap::challengeNewcomer(std::string const & target)
{
	std::string challenges[5] = {
		"Wanna make a car castle ?",
		"Let's run backward around the school.",
		"I eat beef i eat sauce and we kiss to see what happens.",
		"Take my hat and put a boob in it.",
		"Depending on the weather tomorrow i'll eat a potato."
	};
	int	energy = this->getEnergyPoints();
	srand(time(NULL));

	if (energy - 25 >= 0)
	{
		this->setEnergyPoints(energy - 25);
		std::cout << "SC4V-TP " << this->getName() << " challenges " << target << " : \"" << challenges[rand() % 5] << "\"" << std::endl;
	}
	else
	{
		this->setEnergyPoints(0);
		std::cout << "SC4V-TP " << this->getName() << " is out of energy !" << std::endl;
	}
}
