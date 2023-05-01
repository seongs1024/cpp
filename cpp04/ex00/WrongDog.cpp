#include <iostream>

#include "WrongDog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongDog::WrongDog(): WrongAnimal("WrongDog") {
	std::cout << "WrongDog Default Constructor" << std::endl;
}

WrongDog::WrongDog( const WrongDog & src ): WrongAnimal("WrongDog") {
	std::cout << "WrongDog Copy Constructor" << std::endl;
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

WrongDog::~WrongDog() {
	std::cout << "WrongDog Destructor" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

WrongDog & WrongDog::operator=( WrongDog const & rhs )
{
	std::cout << "WrongDog Assign Operator" << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/
void WrongDog::makeSound(void) const {
	std::cout << "W...BARK" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */