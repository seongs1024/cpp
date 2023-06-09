/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongspa <seongspa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:53:28 by seongspa          #+#    #+#             */
/*   Updated: 2023/05/01 11:53:29 by seongspa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {

public:

    Fixed(Fixed const & a);
    Fixed(void);
    ~Fixed(void);

    Fixed & operator=(Fixed const & rhs);

    int getRawBits(void) const;
    void setRawBits(int const raw);
private:
    int _fixed_number;
    static const int    FRACT_BITS = 8;
};

#endif /* FIXED_HPP */
