#include "ScavTrap.hpp"

ScavTrap :: ScavTrap()
{
	this->name = "ScavTrap";
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap :: ScavTrap(std::string name)
{
	this->name = name;
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap :: ~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap :: ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	*this = other;
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap :: operator=(const ScavTrap& other)
{
	this->name = other.name;
	this->hit_points = other.hit_points;
	this->energy_points = other.energy_points;
	this->attack_damage = other.attack_damage;
	std::cout << "ScavTrap assignation operator called" << std::endl;
	return (*this);
}

void	ScavTrap :: attack (const std::string& target)
{
	if (this->hit_points < 1)
	{
		std::cout << this->name << " is dead" << std::endl;
		return ;
	}
	if (this->energy_points < 1)
	{
		std::cout << this->name << " is out of energy" << std::endl;
		return ;
	}
	std::cout << this->name << " Outra mensagem de ataque: attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
	this->energy_points -= 1;
}

void ScavTrap :: guardGate()
{
	std::cout << this->name << " has entered in Gate keeper mode" << std::endl;
}
