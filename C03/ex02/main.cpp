#include "FragTrap.hpp"

int	main()
{
	FragTrap	fragTrap("PireXa");
	fragTrap.attack("target");
	fragTrap.takeDamage(10);
	fragTrap.beRepaired(5);
	fragTrap.highFivesGuys();
	return (0);
}
