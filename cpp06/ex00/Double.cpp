#include "Double.hpp"
#include <sstream>
#include <limits>

// Constructors
Double::Double(std::string &lit)
{
	std::stringstream ss(lit);

	ss >> _value;
	if (ss.fail())
		throw ImpossibleConversionException();
}

Double::Double(const Double &copy): AType()
{
	*this = copy;
}

// Destructor
Double::~Double()
{
}


// Operators
Double & Double::operator=(const Double &assign)
{
	if (this != &assign)
		_value = assign._value;
	return *this;
}

Double::operator char() const
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

Double::operator int() const
{
	if(_value > std::numeric_limits<int>::max() ||
		_value < std::numeric_limits<int>::min())
		throw ImpossibleConversionException();
	return static_cast<int>(_value);
}

Double::operator float() const
{
	if(_value > std::numeric_limits<float>::max() ||
		_value < -std::numeric_limits<float>::max())
		throw ImpossibleConversionException();
	return static_cast<float>(_value);
}

Double::operator double() const
{
	return _value;
}
