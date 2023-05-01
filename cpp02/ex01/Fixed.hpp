/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongspa <seongspa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:53:42 by seongspa          #+#    #+#             */
/*   Updated: 2023/05/01 11:53:44 by seongspa         ###   ########.fr       */
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
private:
    int _fixed_number;
    static const int    FRACT_BITS = 8;
};

std::ostream & operator<<(std::ostream & o, Fixed const & i);

#endif /* FIXED_HPP */
