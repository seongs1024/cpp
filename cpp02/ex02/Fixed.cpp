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

Fixed & Fixed::min(Fixed & a, Fixed & b) {
    if (a <= b)
        return (a);
    return (b);
}

Fixed const & Fixed::min(Fixed const & a, Fixed const & b) {
    if (a <= b)
        return (a);
    return (b);
}

Fixed & Fixed::max(Fixed & a, Fixed & b) {
    if (a >= b)
        return (a);
    return (b);
}

Fixed const & Fixed::max(Fixed const & a, Fixed const & b) {
    if (a >= b)
        return (a);
    return (b);
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

bool Fixed::operator>(Fixed const & rhs) const {
    return (this->getRawBits() > rhs.getRawBits());
}

bool Fixed::operator<(Fixed const & rhs) const {
    return (this->getRawBits() < rhs.getRawBits());
}

bool Fixed::operator>=(Fixed const & rhs) const {
    return (this->getRawBits() >= rhs.getRawBits());
}

bool Fixed::operator<=(Fixed const & rhs) const {
    return (this->getRawBits() <= rhs.getRawBits());
}

bool Fixed::operator==(Fixed const & rhs) const {
    return (this->getRawBits() == rhs.getRawBits());
}

bool Fixed::operator!=(Fixed const & rhs) const {
    return (this->getRawBits() != rhs.getRawBits());
}

Fixed Fixed::operator+(Fixed const & rhs) const {
    Fixed res;
    res.setRawBits(this->getRawBits() + rhs.getRawBits());
    return (res);
}

Fixed Fixed::operator-(Fixed const & rhs) const {
    Fixed res;
    res.setRawBits(this->getRawBits() - rhs.getRawBits());
    return (res);
}

Fixed Fixed::operator*(Fixed const & rhs) const {
    return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed Fixed::operator/(Fixed const & rhs) const {
    return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed & Fixed::operator++(void) {
    ++this->_fixed_number;
    return (*this);
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    ++(*this);
    return (temp);
}

Fixed & Fixed::operator--(void) {
    --this->_fixed_number;
    return (*this);
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    --(*this);
    return (temp);
}
