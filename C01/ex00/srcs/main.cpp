#include "../inc/Zombie.hpp"

int main()
{
	Zombie *zombie = newZombie("Zombie");
	zombie->announce();
	delete zombie;

	randomChump("Random");
	return (0);
}
