#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
	this->name = "default";
	this->hit_points = this->FragTrap::hit_points;
	this->energy_points = this->ScavTrap::energy_points;
	this->attack_damage = this->FragTrap::attack_damage;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name), ScavTrap(name), FragTrap(name)
{
	std::cout << "DiamondTrap constructor called" << std::endl;
	this->name = name;
	this->ClapTrap::name = name + "_clap_name";
	this->hit_points = this->FragTrap::hit_points;
	this->energy_points = this->ScavTrap::energy_points;
	this->attack_damage = this->FragTrap::attack_damage;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	*this = other;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << "DiamondTrap assignation operator called" << std::endl;
	this->name = other.name;
	this->ClapTrap::name = other.ClapTrap::name;
	this->hit_points = other.hit_points;
	this->energy_points = other.energy_points;
	this->attack_damage = other.attack_damage;
	return *this;
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name: " << this->name << std::endl;
	std::cout << "ClapTrap name: " << this->ClapTrap::name << std::endl;
}
