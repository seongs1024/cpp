/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongspa <seongspa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:53:24 by seongspa          #+#    #+#             */
/*   Updated: 2023/05/01 11:53:25 by seongspa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Fixed.hpp"

/******************************************************************************/
/*                                                                            */
/*     Member functions                                                       */
/*                                                                            */
/******************************************************************************/

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_fixed_number);
}

void Fixed::setRawBits(int const raw) {
    this->_fixed_number = raw;
}

/******************************************************************************/
/*                                                                            */
/*     Constructors                                                           */
/*                                                                            */
/******************************************************************************/

Fixed::Fixed(Fixed const & a) {
    std::cout << "Copy constructor called" << std::endl;
    *this = a;
}

Fixed::Fixed(void): _fixed_number(0) {
    std::cout << "Default constructor called" << std::endl;
}

/******************************************************************************/
/*                                                                            */
/*     Destructor                                                             */
/*                                                                            */
/******************************************************************************/

Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
}

/******************************************************************************/
/*                                                                            */
/*     Operators                                                              */
/*                                                                            */
/******************************************************************************/

Fixed &
Fixed::operator=(Fixed const & rhs) {
    std::cout << "Copy assignment operator called" << std::endl;
    this->setRawBits(rhs.getRawBits());
    return *this;
}
