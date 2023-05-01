/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongspa <seongspa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:58:58 by seongspa          #+#    #+#             */
/*   Updated: 2023/05/01 16:21:03 by seongspa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Brain.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Brain::Brain() {
	std::cout << "Brain Default Constructor" << std::endl;
}

Brain::Brain( const Brain & src ) {
	std::cout << "Brain Copy Constructor" << std::endl;
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Brain::~Brain() {
	std::cout << "Brain Destructor" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Brain & Brain::operator=( Brain const & rhs )
{
	std::cout << "Brain Deep Copy Assign Operator" << std::endl;
	if (this != &rhs)
	{
		for (size_t i = 0; i < NUM_IDEAS; i++) {
			this->_ideas[i] = rhs._ideas[i];
		}
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */