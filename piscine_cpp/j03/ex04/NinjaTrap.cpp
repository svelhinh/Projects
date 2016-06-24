#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(std::string const name): ClapTrap(name)
{
	std::cout << "\033[34mNINJ4-TP " << name << " created\033[0m" << std::endl;
	return;
}

NinjaTrap::NinjaTrap(NinjaTrap const & src, std::string const name): ClapTrap(name)
{
	*this = src;
	std::cout << "NINJ4-TP " << name << " created by copy" << std::endl;
	return;
}

NinjaTrap::~NinjaTrap()
{
	std::cout << "\033[31mNINJ4-TP " << this->getName() << " destructed\033[0m" << std::endl;
	return;
}

NinjaTrap & NinjaTrap::operator=(NinjaTrap const & rhs)
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

void			NinjaTrap::rangedAttack(std::string const & target)
{
	std::cout << "NINJ4-TP " << this->getName() << " attacks "
	<< target << " at range, causing " << this->getRangedAttackDamage()
	<< " points of damage !" << std::endl;
}

void			NinjaTrap::meleeAttack(std::string const & target)
{
	std::cout << "NINJ4-TP " << this->getName() << " attacks "
	<< target << " at melee, causing " << this->getRangedAttackDamage()
	<< " points of damage !" << std::endl;
}

void			NinjaTrap::takeDamage(unsigned int amount)
{
	int life = this->getHitPoints();
	int shield = this->getArmorDamageReduction();

	if (life + shield - (int)amount > 0)
	{
		this->setHitPoints(life + shield - amount);
		std::cout << "NINJ4-TP " << this->getName() << " takes "
		<< amount << " points of damage !" << std::endl;
	}
	else
	{
		this->setHitPoints(0);
		std::cout << "NINJ4-TP " << this->getName() << " is dead" << std::endl;
	}
}

void			NinjaTrap::beRepaired(unsigned int amount)
{
	unsigned int life = this->getHitPoints();
	unsigned int max = this->getMaxHitPoints();

	if (life + amount <= max)
		this->setHitPoints(life + amount);
	else
		this->setHitPoints(max);
	std::cout << "NINJ4-TP " << this->getName() << " has "
	<< this->getHitPoints() << " HP" << std::endl;
}

void			NinjaTrap::ninjaShoebox(std::string const & target)
{
	std::string attacks[5] = {
		"Ninja",
		"Ninjaaa",
		"Ninjaaaaaaa",
		"Ninjaaaaaaaaaaaa",
		"Ninjaaaaaaaaaaaaaaaaaaaaaa"
	};
	int	energy = this->getEnergyPoints();
	srand(time(NULL));

	if (energy - 25 >= 0)
	{
		this->setEnergyPoints(energy - 25);
		std::cout << "NINJ4-TP " << this->getName() << " attacks " << target << " : \"" << attacks[rand() % 5] << "\"" << std::endl;
	}
	else
	{
		this->setEnergyPoints(0);
		std::cout << "NINJ4-TP " << this->getName() << " is out of energy !" << std::endl;
	}
}
