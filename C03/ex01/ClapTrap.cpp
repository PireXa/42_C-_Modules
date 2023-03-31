#include "ClapTrap.hpp"

ClapTrap :: ClapTrap()
{
	this->name = "ClapTrap";
	this->hit_points = 10;
	this->energy_points = 10;
	this->attack_damage = 0;
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap :: ClapTrap(std::string name)
{
	this->name = name;
	this->hit_points = 10;
	this->energy_points = 10;
	this->attack_damage = 0;
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap :: ~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap :: ClapTrap(const ClapTrap& other)
{
	*this = other;
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap& ClapTrap :: operator=(const ClapTrap& other)
{
	this->name = other.name;
	this->hit_points = other.hit_points;
	this->energy_points = other.energy_points;
	this->attack_damage = other.attack_damage;
	std::cout << "ClapTrap assignation operator called" << std::endl;
	return (*this);
}

void	ClapTrap :: attack (const std::string& target)
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
	std::cout << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
	this->energy_points -= 1;
}

void ClapTrap :: takeDamage(unsigned int amount)
{
	if (this->hit_points < 1)
	{
		std::cout << this->name << " is dead" << std::endl;
		return ;
	}
	std::cout << this->name << " takes " << amount << " damage" << std::endl;
	this->hit_points -= amount;
}

void ClapTrap :: beRepaired(unsigned int amount)
{
	if (this->energy_points < 1)
	{
		std::cout << this->name << " is out of energy" << std::endl;
		return ;
	}
	std::cout << this->name << " is repaired by " << amount << std::endl;
	this->hit_points += amount;
	this->energy_points -= 1;
}
