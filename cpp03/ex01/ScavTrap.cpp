/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongspa <seongspa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:55:00 by seongspa          #+#    #+#             */
/*   Updated: 2023/05/01 11:55:00 by seongspa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "ScavTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScavTrap::ScavTrap(std::string name): ClapTrap(name) {
	this->_health = 100;
	this->_energy = 50;
	this->_damage = 20;
	std::cout << "ScavTrap is created"
		<< "\nName: " << this->_name
		<< "\nHealth: " << this->_health
		<< "\nEnergy: " << this->_energy
		<< "\nDamage: " << this->_damage
		<< std::endl;
}

ScavTrap::ScavTrap(const ScavTrap & src): ClapTrap(src._name) {
	std::cout << "ScavTrap is copyed" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << this->_name << "is destroyed" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ScavTrap &				ScavTrap::operator=( ScavTrap const & rhs )
{
	std::cout << "ScavTrap is assigned" << std::endl;
	this->_name = rhs._name;
	this->_health = rhs._health;
	this->_energy = rhs._energy;
	this->_damage = rhs._damage;
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/
void ScavTrap::attack(const std::string & target) {
	if (this->_health == 0) {
		std::cout << "ScavTrap " << this->_name << " is already dead." << std::endl;
		return;
	}
	if (this->_energy == 0) {
		std::cout << "ScavTrap " << this->_name << " is out of energy." << std::endl;
		return;
	}
	std::cout
		<< "ScavTrap " << this->_name << " attacks " << target 
		<< ", causing " << this->_damage << " points of damage!" << std::endl;
	this->_energy--;
}

void ScavTrap::guardGate(void) {
	std::cout << "GUARD GATE MODE" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */