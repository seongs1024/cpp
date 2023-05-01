/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongspa <seongspa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:59:02 by seongspa          #+#    #+#             */
/*   Updated: 2023/05/01 16:21:15 by seongspa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog(): Animal("Dog") {
	std::cout << "Dog Default Constructor" << std::endl;
}

Dog::Dog( const Dog & src ): Animal("Dog") {
	std::cout << "Dog Copy Constructor" << std::endl;
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog() {
	std::cout << "Dog Destructor" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Dog & Dog::operator=( Dog const & rhs )
{
	std::cout << "Dog Deep Copy Assign Operator" << std::endl;
	Animal::operator=(rhs);
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