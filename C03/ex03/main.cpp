#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap diamond("Diamond");
	diamond.whoAmI();
	diamond.attack("enemy");
	diamond.takeDamage(10);
	diamond.beRepaired(10);
	diamond.highFivesGuys();
	return (0);
}
