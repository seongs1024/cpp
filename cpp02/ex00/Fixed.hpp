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
