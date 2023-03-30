#include "../inc/Zombie.hpp"

int main()
{
	Zombie *zombie = zombieHorde(10, "Runners");
	for (int i = 0; i < 10; i++)
	{
		zombie[i].announce();
	}
	delete [] zombie;
}
