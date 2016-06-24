#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"

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


	NinjaTrap *ya = new NinjaTrap("ya");
	NinjaTrap *titi = new NinjaTrap("titi");

	ya->rangedAttack(titi->getName());
	titi->takeDamage(ya->getRangedAttackDamage());
	ya->meleeAttack(titi->getName());
	titi->takeDamage(ya->getRangedAttackDamage());
	titi->takeDamage(ya->getRangedAttackDamage());
	titi->takeDamage(ya->getRangedAttackDamage());
	titi->takeDamage(ya->getRangedAttackDamage());
	titi->takeDamage(ya->getRangedAttackDamage());
	titi->beRepaired(30);
	titi->takeDamage(ya->getRangedAttackDamage());
	titi->beRepaired(30);
	titi->beRepaired(30);
	titi->beRepaired(30);
	titi->beRepaired(30);
	ya->ninjaShoebox(titi->getName());

	delete ya;
	delete titi;
	return 0;
}
