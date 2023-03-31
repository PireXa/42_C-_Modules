#include "ScavTrap.hpp"

int	main()
{
	ScavTrap	scav("ScavTrap");
	scav.attack("target");
	scav.takeDamage(10);
	scav.beRepaired(10);
	scav.guardGate();
	return (0);
}
