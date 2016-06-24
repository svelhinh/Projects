#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string const name): _hit_points(100), _max_hit_points(100), _energy_points(100), _max_energy_points(100), _level(1), _name(name), _melee_attack_damage(30), _ranged_attack_damage(20), _armor_damage_reduction(5)
{
	std::cout << "\033[34mClapTrap " << name << " created\033[0m" << std::endl;
	return;
}

ClapTrap::ClapTrap(ClapTrap const & src, std::string const name): _hit_points(100), _max_hit_points(100), _energy_points(100), _max_energy_points(100), _level(1), _name(name), _melee_attack_damage(30), _ranged_attack_damage(20), _armor_damage_reduction(5)
{
	*this = src;
	std::cout << "ClapTrap " << name << " created by copy" << std::endl;
	return;
}

ClapTrap::~ClapTrap()
{
	std::cout << "\033[31mClapTrap " << this->getName() << " destructed\033[0m" << std::endl;
	return;
}

int		ClapTrap::getHitPoints() const
{
	return this->_hit_points;
}

void	ClapTrap::setHitPoints(const int hp)
{
	this->_hit_points = hp;
}

int		ClapTrap::getMaxHitPoints() const
{
	return this->_max_hit_points;
}

int		ClapTrap::getEnergyPoints() const
{
	return this->_energy_points;
}

void	ClapTrap::setEnergyPoints(int const ep)
{
	this->_energy_points = ep;
}

int		ClapTrap::getMaxEnergyPoints() const
{
	return this->_max_energy_points;
}

int		ClapTrap::getLevel() const
{
	return this->_level;
}

std::string		ClapTrap::getName() const
{
	return this->_name;
}

int		ClapTrap::getMeleeAttackDamage() const
{
	return this->_melee_attack_damage;
}

int		ClapTrap::getRangedAttackDamage() const
{
	return this->_ranged_attack_damage;
}

int		ClapTrap::getArmorDamageReduction() const
{
	return this->_armor_damage_reduction;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & rhs)
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
