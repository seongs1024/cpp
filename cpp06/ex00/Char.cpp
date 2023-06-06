#include "Char.hpp"
#include <sstream>

// Constructors
Char::Char(std::string &lit)
{
	std::stringstream ss(lit);

	ss >> _value;
	if (ss.fail())
		throw ImpossibleConversionException();
}

Char::Char(const Char &copy): AType()
{
	*this = copy;
}

// Destructor
Char::~Char()
{
}


// Operators
Char & Char::operator=(const Char &assign)
{
	if (this != &assign)
		_value = assign._value;
	return *this;
}

Char::operator char() const
{
	return _value;
}

Char::operator int() const
{
	return static_cast<int>(_value);
}

Char::operator float() const
{
	return static_cast<float>(_value);
}

Char::operator double() const
{
	return static_cast<double>(_value);
}
