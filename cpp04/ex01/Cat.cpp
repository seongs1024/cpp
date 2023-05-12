/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongspa <seongspa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:59:00 by seongspa          #+#    #+#             */
/*   Updated: 2023/05/12 13:38:12 by seongspa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Cat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat(): Animal("Cat") {
	std::cout << "Cat Default Constructor" << std::endl;
	this->_brain = new Brain();
}

Cat::Cat( const Cat & src ): Animal("Cat") {
	std::cout << "Cat Copy Constructor" << std::endl;
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat() {
	if (this->_brain) {
		delete this->_brain;
		this->_brain = NULL;
	}
	std::cout << "Cat Destructor" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cat & Cat::operator=( Cat const & rhs )
{
	Animal::operator=(rhs);
	std::cout << "Cat Deep Copy Assign Operator" << std::endl;
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
void Cat::makeSound(void) const {
	std::cout << "MEOW" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */