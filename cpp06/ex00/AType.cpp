#include "AType.hpp"

AType::AType()
{
}

// Constructors
AType::AType(const AType &copy)
{
	(void) copy;
}


// Destructor
AType::~AType()
{
}


// Operators
AType & AType::operator=(const AType &assign)
{
	(void) assign;
	return *this;
}

bool AType::printable(char c)
{
    return c >= 0x20 && c < 0x7f;;
}

bool AType::in_digit(char c)
{
	return c >= '0' && c <= '9';
}

// Exceptions
const char * AType::ImpossibleConversionException::what() const throw()
{
	return "impossible";
}

const char *AType::NonDisplayableException::what() const throw()
{
    return "Non displayable";
}
