#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	FragTrap *bob = new FragTrap("bob");
	FragTrap *yo = new FragTrap("yo");

	bob->rangedAttack(yo->getName());
	yo->takeDamage(bob->getRangedAttackDamage());
	bob->meleeAttack(yo->getName());
	yo->takeDamage(bob->getRangedAttackDamage());
	yo->takeDamage(bob->getRangedAttackDamage());
	yo->takeDamage(bob->getRangedAttackDamage());
	yo->takeDamage(bob->getRangedAttackDamage());
	yo->takeDamage(bob->getRangedAttackDamage());
	yo->beRepaired(30);
	yo->takeDamage(bob->getRangedAttackDamage());
	yo->beRepaired(30);
	yo->beRepaired(30);
	yo->beRepaired(30);
	yo->beRepaired(30);
	bob->vaulthunter_dot_exe(yo->getName());

	delete bob;
	delete yo;

	ScavTrap *toto = new ScavTrap("toto");
	ScavTrap *scav = new ScavTrap("scav");

	toto->rangedAttack(scav->getName());
	scav->takeDamage(toto->getRangedAttackDamage());
	toto->meleeAttack(scav->getName());
	scav->takeDamage(toto->getRangedAttackDamage());
	scav->takeDamage(toto->getRangedAttackDamage());
	scav->takeDamage(toto->getRangedAttackDamage());
	scav->takeDamage(toto->getRangedAttackDamage());
	scav->takeDamage(toto->getRangedAttackDamage());
	scav->beRepaired(30);
	scav->takeDamage(toto->getRangedAttackDamage());
	scav->beRepaired(30);
	scav->beRepaired(30);
	scav->beRepaired(30);
	scav->beRepaired(30);
	toto->challengeNewcomer(scav->getName());

	delete toto;
	delete scav;
	return 0;
}
