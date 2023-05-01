/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongspa <seongspa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:59:00 by seongspa          #+#    #+#             */
/*   Updated: 2023/05/01 16:41:29 by seongspa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Cat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat(): IAnimal("Cat") {
	std::cout << "Cat Default Constructor" << std::endl;
}

Cat::Cat( const Cat & src ): IAnimal("Cat") {
	std::cout << "Cat Copy Constructor" << std::endl;
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat() {
	std::cout << "Cat Destructor" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cat & Cat::operator=( Cat const & rhs )
{
	std::cout << "Cat Deep Copy Assign Operator" << std::endl;
	IAnimal::operator=(rhs);
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