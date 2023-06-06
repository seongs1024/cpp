#include "Nan.hpp"

// Constructors
Nan::Nan()
{
}

Nan::Nan(const Nan &copy): AType()
{
	(void) copy;
}

// Destructor
Nan::~Nan()
{
}


// Operators
Nan & Nan::operator=(const Nan &assign)
{
	(void) assign;
	return *this;
}

// Exceptions
const char * Nan::NanException::what() const throw()
{
	return "nan";
}

Nan::operator char() const
{
	throw ImpossibleConversionException();
}

Nan::operator int() const
{
	throw ImpossibleConversionException();
}

Nan::operator float() const
{
	throw NanException();
}

Nan::operator double() const
{
	throw NanException();
}
