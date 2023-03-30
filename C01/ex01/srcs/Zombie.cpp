#include "../inc/Zombie.hpp"

Zombie :: Zombie()
{
	std::cout << "Zombie is created" << std::endl;
}

Zombie :: ~Zombie()
{
	std::cout << name << " is dead" << std::endl;
}

void	Zombie :: announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie :: setName(std::string name)
{
	this->name = name;
}
