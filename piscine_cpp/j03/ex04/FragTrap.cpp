#include "FragTrap.hpp"

FragTrap::FragTrap(std::string const name): ClapTrap(name)
{
	std::cout << "\033[34mFR4G-TP " << name << " created\033[0m" << std::endl;
	return;
}

FragTrap::FragTrap(FragTrap const & src, std::string const name): ClapTrap(name)
{
	*this = src;
	std::cout << "FR4G-TP " << name << " created by copy" << std::endl;
	return;
}

FragTrap::~FragTrap()
{
	std::cout << "\033[31mFR4G-TP " << this->getName() << " destructed\033[0m" << std::endl;
	return;
}

FragTrap & FragTrap::operator=(FragTrap const & rhs)
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

void			FragTrap::rangedAttack(std::string const & target)
{
	std::cout << "FR4G-TP " << this->getName() << " attacks "
	<< target << " at range, causing " << this->getRangedAttackDamage()
	<< " points of damage !" << std::endl;
}

void			FragTrap::meleeAttack(std::string const & target)
{
	std::cout << "FR4G-TP " << this->getName() << " attacks "
	<< target << " at melee, causing " << this->getRangedAttackDamage()
	<< " points of damage !" << std::endl;
}

void			FragTrap::takeDamage(unsigned int amount)
{
	int life = this->getHitPoints();
	int shield = this->getArmorDamageReduction();

	if (life + shield - (int)amount > 0)
	{
		this->setHitPoints(life + shield - amount);
		std::cout << "FR4G-TP " << this->getName() << " takes "
		<< amount << " points of damage !" << std::endl;
	}
	else
	{
		this->setHitPoints(0);
		std::cout << "FR4G-TP " << this->getName() << " is dead" << std::endl;
	}
}

void			FragTrap::beRepaired(unsigned int amount)
{
	unsigned int life = this->getHitPoints();
	unsigned int max = this->getMaxHitPoints();

	if (life + amount <= max)
		this->setHitPoints(life + amount);
	else
		this->setHitPoints(max);
	std::cout << "FR4G-TP " << this->getName() << " has "
	<< this->getHitPoints() << " HP" << std::endl;
}

void			FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	std::string attacks[5] = {
		"I am a tornado of death and bullets!",
		"Wow, did I really do that?",
		"You call yourself a badass?",
		"Don't tell me that wasn't awesome!",
		"Step right up, to the Bulletnator 9000!"
	};
	int	energy = this->getEnergyPoints();
	srand(time(NULL));

	if (energy - 25 >= 0)
	{
		this->setEnergyPoints(energy - 25);
		std::cout << "FR4G-TP " << this->getName() << " attacks " << target << " : \"" << attacks[rand() % 5] << "\"" << std::endl;
	}
	else
	{
		this->setEnergyPoints(0);
		std::cout << "FR4G-TP " << this->getName() << " is out of energy !" << std::endl;
	}
}
