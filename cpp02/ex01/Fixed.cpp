/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongspa <seongspa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:53:38 by seongspa          #+#    #+#             */
/*   Updated: 2023/05/01 11:53:39 by seongspa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>

#include "Fixed.hpp"

/******************************************************************************/
/*                                                                            */
/*     Member functions                                                       */
/*                                                                            */
/******************************************************************************/

int Fixed::getRawBits(void) const {
    return (this->_fixed_number);
}

void Fixed::setRawBits(int const raw) {
    this->_fixed_number = raw;
}

float Fixed::toFloat(void) const {
    return (static_cast<float>(this->getRawBits()) / (1 << FRACT_BITS));
}

int Fixed::toInt(void) const {
    return (this->getRawBits() >> FRACT_BITS);
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

Fixed::Fixed(int const n): _fixed_number(n << FRACT_BITS) {
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const f): _fixed_number(roundf(f * (1 << FRACT_BITS))) {
    std::cout << "Float constructor called" << std::endl;
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

std::ostream & operator<<(std::ostream & o, Fixed const & i) {
    o << i.toFloat();
    return o;
}
