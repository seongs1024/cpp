/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongspa <seongspa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:59:05 by seongspa          #+#    #+#             */
/*   Updated: 2023/05/01 13:59:23 by seongspa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "WrongAnimal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongAnimal::WrongAnimal(): _type("WrongAnimal") {
	std::cout << "WrongAnimal Default Constructor" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal & src ) {
	std::cout << "WrongAnimal Copy Constructor" << std::endl;
	*this = src;
}

WrongAnimal::WrongAnimal(std::string type): _type(type) {
	std::cout << "WrongAnimal User Defined Constructor" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal Destructor" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

WrongAnimal & WrongAnimal::operator=( WrongAnimal const & rhs )
{
	std::cout << "WrongAnimal Assign Operator" << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/
void WrongAnimal::makeSound(void) const {
	std::cout << "Wrong..." << std::endl;
}

std::string WrongAnimal::getType(void) const {
	return (this->_type);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */