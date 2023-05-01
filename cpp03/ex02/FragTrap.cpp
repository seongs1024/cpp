/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongspa <seongspa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:55:25 by seongspa          #+#    #+#             */
/*   Updated: 2023/05/01 11:55:27 by seongspa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "FragTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

FragTrap::FragTrap(std::string name): ClapTrap(name) {
	this->_health = 100;
	this->_energy = 100;
	this->_damage = 30;
	std::cout << "FragTrap is created"
		<< "\nName: " << this->_name
		<< "\nHealth: " << this->_health
		<< "\nEnergy: " << this->_energy
		<< "\nDamage: " << this->_damage
		<< std::endl;
}

FragTrap::FragTrap(const FragTrap & src): ClapTrap(src._name) {
	std::cout << "FragTrap is copyed" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << this->_name << "is destroyed" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

FragTrap &				FragTrap::operator=( FragTrap const & rhs )
{
	std::cout << "FragTrap is assigned" << std::endl;
	this->_name = rhs._name;
	this->_health = rhs._health;
	this->_energy = rhs._energy;
	this->_damage = rhs._damage;
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/
void FragTrap::highFivesGuys(void) {
	std::cout << "HIGH FIVE PLZ!" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */