#include "FragTrap.hpp"

FragTrap::FragTrap(std::string const name): _hit_points(100), _max_hit_points(100), _energy_points(100), _max_energy_points(100), _level(1), _name(name), _melee_attack_damage(30), _ranged_attack_damage(20), _armor_damage_reduction(5)
{
	std::cout << "\033[34mFragTrap " << name << " created\033[0m" << std::endl;
	return;
}

FragTrap::FragTrap(FragTrap const & src, std::string const name): _hit_points(100), _max_hit_points(100), _energy_points(100), _max_energy_points(100), _level(1), _name(name), _melee_attack_damage(30), _ranged_attack_damage(20), _armor_damage_reduction(5)
{
	*this = src;
	std::cout << "FragTrap " << name << " created by copy" << std::endl;
	return;
}

FragTrap::~FragTrap()
{
	std::cout << "\033[31mFragTrap " << this->getName() << " destructed\033[0m" << std::endl;
	return;
}

int		FragTrap::getHitPoints() const
{
	return this->_hit_points;
}

void	FragTrap::setHitPoints(const int hp)
{
	this->_hit_points = hp;
}

int		FragTrap::getMaxHitPoints() const
{
	return this->_max_hit_points;
}

int		FragTrap::getEnergyPoints() const
{
	return this->_energy_points;
}

void	FragTrap::setEnergyPoints(int const ep)
{
	this->_energy_points = ep;
}

int		FragTrap::getMaxEnergyPoints() const
{
	return this->_max_energy_points;
}

int		FragTrap::getLevel() const
{
	return this->_level;
}

std::string		FragTrap::getName() const
{
	return this->_name;
}

int		FragTrap::getMeleeAttackDamage() const
{
	return this->_melee_attack_damage;
}

int		FragTrap::getRangedAttackDamage() const
{
	return this->_ranged_attack_damage;
}

int		FragTrap::getArmorDamageReduction() const
{
	return this->_armor_damage_reduction;
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
