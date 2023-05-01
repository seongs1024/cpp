/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongspa <seongspa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:54:06 by seongspa          #+#    #+#             */
/*   Updated: 2023/05/01 11:54:07 by seongspa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {

public:

    Fixed(Fixed const & a);
    Fixed(int const n);
    Fixed(float const f);
    Fixed(void);
    ~Fixed(void);

    Fixed & operator=(Fixed const & rhs);

    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;

    static Fixed & min(Fixed & a, Fixed & b);
    static Fixed const & min(Fixed const & a, Fixed const & b);
    static Fixed & max(Fixed & a, Fixed & b);
    static Fixed const & max(Fixed const & a, Fixed const & b);

    bool operator>(Fixed const & rhs) const;
    bool operator<(Fixed const & rhs) const;
    bool operator>=(Fixed const & rhs) const;
    bool operator<=(Fixed const & rhs) const;
    bool operator==(Fixed const & rhs) const;
    bool operator!=(Fixed const & rhs) const;

    Fixed operator+(Fixed const & rhs) const;
    Fixed operator-(Fixed const & rhs) const;
    Fixed operator*(Fixed const & rhs) const;
    Fixed operator/(Fixed const & rhs) const;

    Fixed & operator++(void);
    Fixed operator++(int);
    Fixed & operator--(void);
    Fixed operator--(int);
private:
    int _fixed_number;
    static const int    FRACT_BITS = 8;
};

std::ostream & operator<<(std::ostream & o, Fixed const & i);

#endif /* FIXED_HPP */
