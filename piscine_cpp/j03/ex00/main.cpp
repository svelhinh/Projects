#include "FragTrap.hpp"

int main(void)
{
	FragTrap bob = FragTrap("bob");
	FragTrap yo = FragTrap("yo");

	bob.rangedAttack(yo.getName());
	yo.takeDamage(bob.getRangedAttackDamage());
	bob.meleeAttack(yo.getName());
	yo.takeDamage(bob.getRangedAttackDamage());
	yo.takeDamage(bob.getRangedAttackDamage());
	yo.takeDamage(bob.getRangedAttackDamage());
	yo.takeDamage(bob.getRangedAttackDamage());
	yo.takeDamage(bob.getRangedAttackDamage());
	yo.beRepaired(30);
	yo.takeDamage(bob.getRangedAttackDamage());
	yo.beRepaired(30);
	yo.beRepaired(30);
	yo.beRepaired(30);
	yo.beRepaired(30);
	bob.vaulthunter_dot_exe(yo.getName());
	return 0;
}
