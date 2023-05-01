/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongspa <seongspa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:59:07 by seongspa          #+#    #+#             */
/*   Updated: 2023/05/01 13:59:21 by seongspa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "WrongCat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongCat::WrongCat(): WrongAnimal("WrongCat") {
	std::cout << "WrongCat Default Constructor" << std::endl;
}

WrongCat::WrongCat( const WrongCat & src ): WrongAnimal("WrongCat") {
	std::cout << "WrongCat Copy Constructor" << std::endl;
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

WrongCat::~WrongCat() {
	std::cout << "WrongCat Destructor" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

WrongCat & WrongCat::operator=( WrongCat const & rhs )
{
	std::cout << "WrongCat Assign Operator" << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/
void WrongCat::makeSound(void) const {
	std::cout << "W...MEOW" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */