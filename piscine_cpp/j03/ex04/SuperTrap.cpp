#include "SuperTrap.hpp"

SuperTrap::SuperTrap(std::string const name): FragTrap(name), NinjaTrap(name)
{
	std::cout << "\033[34mSUPER-TP " << name << " created\033[0m" << std::endl;
	return;
}

SuperTrap::SuperTrap(SuperTrap const & src, std::string const name): FragTrap(name), NinjaTrap(name)
{
	*this = src;
	std::cout << "SUPER-TP " << name << " created by copy" << std::endl;
	return;
}

SuperTrap::~SuperTrap()
{
	std::cout << "\033[31mSUPER-TP " << this->getName() << " destructed\033[0m" << std::endl;
	return;
}

SuperTrap & SuperTrap::operator=(SuperTrap const & rhs)
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
