#include "NegativeInf.hpp"

// Constructors
NegativeInf::NegativeInf()
{
}

NegativeInf::NegativeInf(const NegativeInf &copy): AType()
{
	(void) copy;
}

// Destructor
NegativeInf::~NegativeInf()
{
}


// Operators
NegativeInf & NegativeInf::operator=(const NegativeInf &assign)
{
	(void) assign;
	return *this;
}

// Exceptions
const char * NegativeInf::NegativeInfException::what() const throw()
{
	return "-inf";
}

NegativeInf::operator char() const
{
	throw ImpossibleConversionException();
}

NegativeInf::operator int() const
{
	throw ImpossibleConversionException();
}

NegativeInf::operator float() const
{
	throw NegativeInfException();
}

NegativeInf::operator double() const
{
	throw NegativeInfException();
}
