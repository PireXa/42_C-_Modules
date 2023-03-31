#include "ClapTrap.hpp"

int main()
{
	ClapTrap clapTrap;
	clapTrap.attack("target");
	clapTrap.takeDamage(5);
	clapTrap.beRepaired(5);
	clapTrap.takeDamage(50);
	clapTrap.beRepaired(50);
	return 0;
}
