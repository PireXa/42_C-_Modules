#include "../inc/Weapon.hpp"

Weapon :: Weapon(std::string type)
{
	this->type = type;
}

Weapon :: ~Weapon()
{
}

const std::string &Weapon :: getType()
{
	return (type);
}

void	Weapon :: setType(std::string type)
{
	std::cout << "Weapon type: " << this->type << " set to " << type << std::endl;
	this->type = type;
}
