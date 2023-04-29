#include <iostream>

#include "ClapTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ClapTrap::ClapTrap(std::string name): _name(name), _health(10), _energy(10), _damage(0)
{
	std::cout << "ClapTrap " << this->_name << " is created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap & src)
{
	std::cout << "ClapTrap is copyed" << std::endl;
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->_name << "is destroyed" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ClapTrap & ClapTrap::operator=(ClapTrap const & rhs)
{
	std::cout << "ClapTrap is assigned" << std::endl;
	this->_name = rhs._name;
	this->_health = rhs._health;
	this->_energy = rhs._energy;
	this->_damage = rhs._damage;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/
void ClapTrap::attack(const std::string & target)
{
	if (this->_health == 0) {
		std::cout << "ClapTrap " << this->_name << " is already dead." << std::endl;
		return;
	}
	if (this->_energy == 0) {
		std::cout << "ClapTrap " << this->_name << " is out of energy." << std::endl;
		return;
	}
	std::cout
		<< "ClapTrap " << this->_name << " attacks " << target 
		<< ", causing " << this->_damage << " points of damage!" << std::endl;
	this->_energy--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_health == 0) {
		std::cout << "ClapTrap " << this->_name << " is already dead." << std::endl;
		return;
	}
	if (this->_health  < amount) {
		this->_health = 0;
		std::cout << "ClapTrap " << this->_name << " has gone." << std::endl;
	} else {
		this->_health -= amount;
		std::cout << "ClapTrap " << this->_name << " took damages, then its health is " << this->_health << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_health == 0) {
		std::cout << "ClapTrap " << this->_name << " is already dead." << std::endl;
		return;
	}
	if (this->_energy == 0) {
		std::cout << "ClapTrap " << this->_name << " is out of energy." << std::endl;
		return;
	}
	this->_health += amount;
	std::cout << "ClapTrap " << this->_name << " is repaired, then its health is " << this->_health << std::endl;
	this->_energy--;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */