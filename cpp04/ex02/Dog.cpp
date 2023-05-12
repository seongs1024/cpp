/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongspa <seongspa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:59:02 by seongspa          #+#    #+#             */
/*   Updated: 2023/05/12 15:34:07 by seongspa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog(): IAnimal("Dog") {
	std::cout << "Dog Default Constructor" << std::endl;
	this->_brain = new Brain();
}

Dog::Dog( const Dog & src ): IAnimal("Dog") {
	std::cout << "Dog Copy Constructor" << std::endl;
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog() {
	if (this->_brain) {
		delete this->_brain;
		this->_brain = NULL;
	}
	std::cout << "Dog Destructor" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Dog & Dog::operator=( Dog const & rhs )
{
	IAnimal::operator=(rhs);
	std::cout << "Dog Deep Copy Assign Operator" << std::endl;
	if (this != &rhs) {
		if (rhs._brain && this->_brain == NULL) {
			this->_brain = new Brain(*rhs._brain);
		} else if (rhs._brain && this->_brain)
			*(this->_brain) = *(rhs._brain);
		else if (rhs._brain == NULL && this->_brain) {
			delete this->_brain;
			this->_brain = NULL;
		}
	}
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/
void Dog::makeSound(void) const {
	std::cout << "BARK" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */