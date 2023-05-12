/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongspa <seongspa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:58:58 by seongspa          #+#    #+#             */
/*   Updated: 2023/05/01 16:29:53 by seongspa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Animal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Animal::Animal(): _type("Animal") {
	std::cout << "Animal Default Constructor" << std::endl;
	this->_brain = new Brain();
}

Animal::Animal( const Animal & src ) {
	std::cout << "Animal Copy Constructor" << std::endl;
	*this = src;
}

Animal::Animal(std::string type): _type(type) {
	std::cout << "Animal User Defined Constructor" << std::endl;
	this->_brain = new Brain();
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Animal::~Animal() {
	std::cout << "Animal Destructor" << std::endl;
	if (this->_brain)
		delete this->_brain;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Animal & Animal::operator=( Animal const & rhs )
{
	std::cout << "Animal Deep Copy Assign Operator" << std::endl;
	if (this != &rhs)
	{
		if (this->_brain && rhs._brain)
			*this->_brain = *rhs._brain;
		else if (this->_brain && !rhs._brain) {
			delete this->_brain;
			this->_brain = NULL;
		} else if (!this->_brain && rhs._brain) {
			this->_brain = new Brain(*rhs._brain);
		} else
			this->_brain = NULL;
		this->_type = rhs._type;
	}
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/
void Animal::makeSound(void) const {
	std::cout << "..." << std::endl;
}

std::string Animal::getType(void) const {
	return (this->_type);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */