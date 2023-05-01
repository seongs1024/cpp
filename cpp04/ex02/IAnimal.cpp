/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongspa <seongspa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:58:58 by seongspa          #+#    #+#             */
/*   Updated: 2023/05/01 16:29:53 by seongspa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "IAnimal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

IAnimal::IAnimal(): _type("IAnimal") {
	std::cout << "IAnimal Default Constructor" << std::endl;
	this->_brain = new Brain();
}

IAnimal::IAnimal( const IAnimal & src ) {
	std::cout << "IAnimal Copy Constructor" << std::endl;
	*this = src;
}

IAnimal::IAnimal(std::string type): _type(type) {
	std::cout << "IAnimal User Defined Constructor" << std::endl;
	this->_brain = new Brain();
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

IAnimal::~IAnimal() {
	std::cout << "IAnimal Destructor" << std::endl;
	if (this->_brain)
		delete this->_brain;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

IAnimal & IAnimal::operator=( IAnimal const & rhs )
{
	std::cout << "IAnimal Deep Copy Assign Operator" << std::endl;
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

std::string IAnimal::getType(void) const {
	return (this->_type);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */