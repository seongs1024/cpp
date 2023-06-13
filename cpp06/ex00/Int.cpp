#include "Int.hpp"
#include <sstream>
#include <limits>

// Constructors
Int::Int(std::string &lit)
{
	std::stringstream ss(lit);

	ss >> _value;
	if (ss.fail())
		throw ImpossibleConversionException();
}

Int::Int(const Int &copy): AType()
{
	*this = copy;
}

// Destructor
Int::~Int()
{
}


// Operators
Int & Int::operator=(const Int &assign)
{
	if (this != &assign)
		_value = assign._value;
	return *this;
}

Int::operator char() const
{
	char c;

	if(_value > std::numeric_limits<char>::max() ||
		_value < 0)
		throw ImpossibleConversionException();
	c = static_cast<char>(_value);
	if (AType::printable(c) == false)
		throw NonDisplayableException();
	return c;
}

Int::operator int() const
{
	return _value;
}

Int::operator float() const
{
	return static_cast<float>(_value);
}

Int::operator double() const
{
	return static_cast<double>(_value);
}
