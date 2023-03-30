#include "../inc/HumanA.hpp"
#include "../inc/HumanB.hpp"

int main()
{
	{
		Weapon club = Weapon("1");
		std::cout << "Weapon type: " << club.getType() << std::endl;
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("2");
		std::cout << "Weapon type: " << club.getType() << std::endl;
		bob.attack();
		std::cout << std::endl;
	}
	{
		Weapon club = Weapon("1");
		std::cout << "Weapon type: " << club.getType() << std::endl;
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("2");
		std::cout << "Weapon type: " << club.getType() << std::endl;
		jim.attack();
	}
	return 0;
}
