#include "PositiveInf.hpp"

// Constructors
PositiveInf::PositiveInf()
{
}

PositiveInf::PositiveInf(const PositiveInf &copy): AType()
{
	(void) copy;
}

// Destructor
PositiveInf::~PositiveInf()
{
}


// Operators
PositiveInf & PositiveInf::operator=(const PositiveInf &assign)
{
	(void) assign;
	return *this;
}

// Exceptions
const char * PositiveInf::PositiveInfException::what() const throw()
{
	return "+inf";
}

PositiveInf::operator char() const
{
	throw ImpossibleConversionException();
}

PositiveInf::operator int() const
{
	throw ImpossibleConversionException();
}

PositiveInf::operator float() const
{
	throw PositiveInfException();
}

PositiveInf::operator double() const
{
	throw PositiveInfException();
}
