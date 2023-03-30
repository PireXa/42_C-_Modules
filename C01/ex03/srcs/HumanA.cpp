#include "../inc/HumanA.hpp"

HumanA :: HumanA(std::string name, Weapon &weapon) : weapon(weapon)
{
	this->name = name;
	this->weapon = weapon;
}

HumanA :: ~HumanA()
{
}

void	HumanA :: attack()
{
	std::cout << name << " attacks with his " << weapon.getType() << std::endl;
}
